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

// -------------------------------------------------------------------------
template < class S > 
Polinomio<S>& Polinomio<S>::operator+( const Polinomio< S >& der ) const
{
  Polinomio<S> resultado;

  

  return resultado;
}

// -------------------------------------------------------------------------
template < class S > 
Polinomio<S>& Polinomio<S>::operator*( const Polinomio< S >& der ) const
{
  Polinomio<S> resultado;

  // TODO #2

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
  // TODO #3
  

  return resultado;
}

#endif // __POLINOMIO__HXX__

// eof - Polinomio.hxx
