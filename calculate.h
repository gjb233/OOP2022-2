#pragma once
template<class T>
T calculate(char expressionType, int x, int y, int z){
    if(expressionType == 'A'){
        return x * x + y * y + z * z;
    }
    else if(expressionType == 'B'){
        return x * y + y / z - x * z;
    }
    else if(expressionType == 'C'){
        return y * 3 * z - x * z / (y - 2) - x * y / (z + 1);
    }
    else return 0;
}