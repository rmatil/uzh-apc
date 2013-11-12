//
//  Util.cpp
//  apcpp-ex2
//
//  Created by Raphael Matile on 07.10.13.
//  Copyright (c) 2013 Raphael Matile. All rights reserved.
//

#include <iostream>
#include "Util.h"



// wheter a nor b should be 0
int gcf(int a, int b) {
    if (a<b) std::swap(a,b);
    
    while (b!=0) {
        a=a-b;
        if (a<b) std::swap(a,b);
    }
    return a;
}