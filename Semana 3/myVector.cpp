#include <vector>
#include <iostream>




int main(){

    std::vector<int> miVec;

    miVec.push_back(1);
    miVec.push_front(2);

    for (int i=0; i< miVec.size(); i++){
        std:cout << miVec[i] << std:endl;
    }

    return 0;
}

