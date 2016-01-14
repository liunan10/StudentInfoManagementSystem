/* 
 * File:   BubbleSort.cpp
 * Author: sunangel liunan Nan Liu Angie Sun
 *
 * Created on February 2, 2014, 11:28 AM
 */

#ifndef BUBBLESORT_H
#define	BUBBLESORT_H

#include "factory.h"

class AbstractSort{
protected:
    AbstractSort(){}
public: 
    virtual void Sort(AbstractDBFactory & factory)=0;
    virtual ~AbstractSort(){}
};

//bubble sort and all other sorts inherit structure from abstract sort
class BubbleSort:public AbstractSort
{
public:
     void Sort (AbstractDBFactory & factory);
     ~BubbleSort(){}
};

#endif	/* BUBBLESORT_H */

