#include<stdio.h>

int main()
{
	FILE *filePointer = fopen("report.csv", "r");
	const int MAX = 100;
	int index = 0; 
	int todayYMDArr[MAX] = {0}, ticketSelectArr[MAX] = {0}, generationArr[MAX] = {0}, 
		orderCountArr[MAX] = {0}, discountPriceArr[MAX] = {0}, discountArr[MAX] = {0};
	
	while(fscanf(filePointer, "%d,%d,%d,%d,%d,%d", &todayYMDArr[index], &ticketSelectArr[index],
				&generationArr[index], &orderCountArr[index], &discountPriceArr[index], &discountArr[index]) != -1){
			index++;
		}
		
		fclose(filePointer);
		
		for(int i = 0; i < index; i++){
			printf("%d %d %d %d %d %d\n", todayYMDArr[i], ticketSelectArr[i],
			generationArr[i], orderCountArr[i], discountPriceArr[i], discountArr[i]);
		}
		
	return 0;
}
