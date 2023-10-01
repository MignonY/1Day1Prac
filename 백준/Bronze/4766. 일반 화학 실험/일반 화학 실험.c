#include <stdio.h>

double prevTemperature;

int main(){
    scanf("%lf", &prevTemperature);

	while (1){
		double curTemperature;
		scanf("%lf", &curTemperature);

		if (curTemperature == 999){
			break;
		}

		printf("%.2lf\n", curTemperature - prevTemperature);

		prevTemperature = curTemperature;
	}

	return 0;
}