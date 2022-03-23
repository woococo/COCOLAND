#include<stdio.h>

int main()
{
	FILE *filePointer = fopen("report.csv", "r");
	const int MAX = 100;
	int index = 0; 
	int todayYMDArr[MAX], ticketSelectArr[MAX], generationArr[MAX], 
		orderCountArr[MAX], discountPriceArr[MAX], discountArr[MAX];
	int sumParkDay=0, sumParkAfter=0, sumTotalDay=0, sumTotalAfter=0;
	int freeCount=0, babyCount=0, childCount=0, teenCount=0, adultCount=0, oldCount=0;
	int discountA=0, discountB=0, discountC=0, discountD=0, discountE=0, discountF=0;
	int finalCount=0, finalPrice=0;
	while(fscanf(filePointer, "%d,%d,%d,%d,%d,%d", &todayYMDArr[index], &ticketSelectArr[index],
				&generationArr[index], &orderCountArr[index], &discountPriceArr[index], &discountArr[index]) != -1){
			index++;
		}
		
		fclose(filePointer);
		int i;
		printf("======================= report.csv =======================\n");
		printf("%-8s %-5s %-10s %-7s %-10s %-10s\n","��¥","����","���ɱ���","����","����","������");
		for(i = 0; i < index; i++){
			printf("%-8d %-5d %-10d %-7d %-10d %-10d\n", todayYMDArr[i], ticketSelectArr[i],
			generationArr[i], orderCountArr[i], discountPriceArr[i], discountArr[i]);
		}
		
		for(int j = 0; j < index; j++){
			switch(ticketSelectArr[j]){
				case 1:
					sumParkDay += orderCountArr[j];
					break;
				case 2:
					sumParkAfter += orderCountArr[j];
					break;
				case 3:
					sumTotalDay += orderCountArr[j];
					break;
				case 4:
					sumTotalAfter += orderCountArr[j];		
					break;
				}
						
			switch(generationArr[j]){
				case 1:
					freeCount += orderCountArr[j];
					break;
				case 2:
					babyCount += orderCountArr[j];
					break;
				case 3:
					childCount += orderCountArr[j];
					break;
				case 4:
					teenCount += orderCountArr[j];
					break;
				case 5:
					adultCount += orderCountArr[j];
					break;
				case 6:
					oldCount += orderCountArr[j];
					break;		
			}
			
			switch(discountArr[j]){
				case 1:
					discountA += orderCountArr[j];
					break;
				case 2:
					discountB += orderCountArr[j];
					break;
				case 3:
					discountC += orderCountArr[j];
					break;
				case 4:
					discountD += orderCountArr[j];
					break;
				case 5:
					discountE += orderCountArr[j];
					break;
				case 6:
					discountF += orderCountArr[j];
					break;		
			}
			finalCount += orderCountArr[j];
			finalPrice += discountPriceArr[j];
		}
		
		
		printf("\n\n==================== %s ====================\n", "������ �Ǹ� ��Ȳ");
		printf("%-20s �� %5d ��\n","��ũ�̿��[1DAY]", sumParkDay);
		printf("%-20s �� %5d ��\n","��ũ�̿��[After4]", sumParkAfter);
		printf("%-20s �� %5d ��\n","�����̿��[1DAY]", sumTotalDay);
		printf("%-20s �� %5d ��\n","�����̿��[After4]", sumTotalAfter);
		
		printf("\n\n==================== %s ====================\n", "���ɺ� �Ǹ� ��Ȳ");
		printf("%-20s �� %5d ��\n","����", freeCount);
		printf("%-20s �� %5d ��\n","����", babyCount);
		printf("%-20s �� %5d ��\n","���", childCount);
		printf("%-20s �� %5d ��\n","û�ҳ�", teenCount);
		printf("%-20s �� %5d ��\n","�", adultCount);
		printf("%-20s �� %5d ��\n","���", oldCount);
		
		
		printf("\n\n==================== %s ====================\n", "���� �Ǹ� ��Ȳ"); 
		printf("%-20s �� %5d ��\n","����", discountA);
		printf("%-20s �� %5d ��\n","�����", discountB);
		printf("%-20s �� %5d ��\n","����������", discountC);
		printf("%-20s �� %5d ��\n","�ް��庴", discountD);
		printf("%-20s �� %5d ��\n","�ӻ��", discountE);
		printf("%-20s �� %5d ��\n","�ٵ���", discountF);
		
		printf("\n\n==================== %s ====================\n", "�� ����  ��Ȳ"); 
		printf("�� %d �� %5d��\n", finalCount, finalPrice); 
		
		return 0;
}
