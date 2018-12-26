#include <iostream>

class Solution{
	bool isNumeric(char* str){
		if(str == NULL){
			return false;
		}
		if(*str == '+' || *str == '-'){
			str++;
		}
		if(*str == '\0'){
			return false;
		}

		int num = 0, dol = 0, nume = 0;
		while(*str){
			if(*str >= '0' || *str <= '9'){
				str++;
				num = 1;
			}
			else if(*str == '.'){
				if(dol > 0 || nume > 0){
					return false;
				}
				str++;
				dol = 1;
			}
			else if(*str == 'e' || *str == 'E'){
				if(num == 0 || nume > 0){
					return false;
				}
				str++;
				nume++;
				if(*str == '+' || *str == '-'){
					str++;
				}
				if(*str == '\0'){
					return false;
				}
			}
			else{
				return false;
			}
		}

		return true;
	}
};
