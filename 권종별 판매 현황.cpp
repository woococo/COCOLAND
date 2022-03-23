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
		printf("%-8s %-5s %-10s %-7s %-10s %-10s\n","날짜","권종","연령구분","수량","가격","우대사항");
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
		
		
		printf("\n\n==================== %s ====================\n", "권종별 판매 현황");
		printf("%-20s 총 %5d 매\n","파크이용권[1DAY]", sumParkDay);
		printf("%-20s 총 %5d 매\n","파크이용권[After4]", sumParkAfter);
		printf("%-20s 총 %5d 매\n","종합이용권[1DAY]", sumTotalDay);
		printf("%-20s 총 %5d 매\n","종합이용권[After4]", sumTotalAfter);
		
		printf("\n\n==================== %s ====================\n", "연령별 판매 현황");
		printf("%-20s 총 %5d 매\n","무료", freeCount);
		printf("%-20s 총 %5d 매\n","유아", babyCount);
		printf("%-20s 총 %5d 매\n","어린이", childCount);
		printf("%-20s 총 %5d 매\n","청소년", teenCount);
		printf("%-20s 총 %5d 매\n","어른", adultCount);
		printf("%-20s 총 %5d 매\n","경로", oldCount);
		
		
		printf("\n\n==================== %s ====================\n", "우대권 판매 현황"); 
		printf("%-20s 총 %5d 매\n","없음", discountA);
		printf("%-20s 총 %5d 매\n","장애인", discountB);
		printf("%-20s 총 %5d 매\n","국가유공자", discountC);
		printf("%-20s 총 %5d 매\n","휴가장병", discountD);
		printf("%-20s 총 %5d 매\n","임산부", discountE);
		printf("%-20s 총 %5d 매\n","다둥이", discountF);
		
		printf("\n\n==================== %s ====================\n", "총 매출  현황"); 
		printf("총 %d 매 %5d원\n", finalCount, finalPrice); 
		
		return 0;
}
