#include <vector>

typedef std::vector<float> TVector;
typedef std:: vector<TVector> TVector2;


void func(TVector2 ml){

    TVector2::iterator mIt = ml.begin();
    TVector::iterator lIt = mIt->begin();

    for(TVector2::iterator i=ml.begin(); i!=ml.end(); i++){

        for(TVector::iterator j=i->begin(); j!= i->end(); j++){
            if( *j < *lIt){
                mIt=i;
                lIt=j;
            }
        }
    }

mIt->erase(lIt);

}


// Elimina el elemento más pequeño de la multilista.