#include "Polinomio.h"
#include <cmath>

#ifndef __POLINOMIO__HXX__
#define __POLINOMIO__HXX__

// -------------------------------------------------------------------------
template < class S > 
Polinomio<S>::
Polinomio( )
{
}

// -------------------------------------------------------------------------
template < class S > 
Polinomio<S>::
~Polinomio( )
{
}

// -------------------------------------------------------------------------
template < class S > 
void Polinomio<S>::FijarCoeficiente( unsigned int grado, const S& coeficiente )
{
  if( grado >= this->size( ) )
    this->resize( grado + 1, S( 0 ) );
  ( *this )[ grado ] = coeficiente;
}

//CUSTOM
template < class S >
S Polinomio<S>::GetCoeficiente(unsigned int grado) const
{
  if (grado < this->size()) {
      return (*this)[grado];
  } else {
      return S(0);
  }
}

// -------------------------------------------------------------------------
template < class S > 
Polinomio<S> Polinomio<S>::operator+( const Polinomio< S >& der ) const
{
  Polinomio<S> resultado;

  // Determinar el grado máximo entre los dos polinomios
  unsigned int maxGrado = std::max(this->size(), der.size());

  // Sumar los coeficientes de los términos correspondientes
  for (unsigned int i = 0; i <= maxGrado; ++i) {
      S coeficiente = S(0);
      if (i < this->size())
          coeficiente += (*this)[i];
      if (i < der.size())
          coeficiente += der[i];
      resultado.FijarCoeficiente(i, coeficiente);
  }

  return resultado;

}

// -------------------------------------------------------------------------
template < class S > 
Polinomio<S> Polinomio<S>::operator*( const Polinomio< S >& der ) const
{
  Polinomio<S> resultado;
  
  const size_t grado_max = this->size() + der.size() - 1;
  resultado.resize(grado_max);
  for (size_t i = 0; i < this->size(); ++i) 
  {
    for (size_t j = 0; j < der.size(); ++j) 
    {
      size_t indice = i + j;
      resultado.FijarCoeficiente(indice,  resultado.GetCoeficiente(indice) + (*this)[i] * der.GetCoeficiente(j));
    }
  }
  return resultado;
}

// -------------------------------------------------------------------------
template < class S > 
S Polinomio<S>::operator()( const S& x ) const
{
  S resultado = S( 0 );
  S base = S( 0 );

  for (int i=0; i< this->size( ); i++){
    base = ( *this )[i];
    resultado+= base * std::pow(x, i);
  }
  return resultado;
}

#endif // __POLINOMIO__HXX__

// eof - Polinomio.hxx
