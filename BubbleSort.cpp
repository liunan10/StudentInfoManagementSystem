/* 
 * File:   main.cpp
 * Author: sunangel liunan Nan Liu Angie Sun
 *
 * Created on February 2, 2014, 11:28 AM
 */
#include "BubbleSort.h"

//bubble sorts the factory data
void BubbleSort::Sort(AbstractDBFactory& factory){ 
    //iterates n^2 times
      for (int k = 1; k <factory.getSize(); k++){
            for (int i = 0; i <factory.getSize()-1;  i++){
                //if 2 adjacent elements out of place, swaps them
                if (factory.less(i, i+1)){
                factory.swap(i, i+1);    
                }
            }
        }       
}
