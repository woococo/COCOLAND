#include<stdio.h>
#include <time.h>

int main()
{
	int ticketSelect, idNumber, backIdNumber, orderCount, discount, age, price, countPrice, discountPrice, totalPrice, again;	
	int ticketSelectArr[10]={0}, orderCountArr[10]={0}, discountArr[10]={0}, discountPriceArr[10] = {0};
	int index = 0;
		 
	// 파크입장권
	const int ADULT_DAY = 56000, TEEN_DAY = 50000, CHILD_DAY = 46000, BABY_DAY = 15000, FREE = 0;
	const int ADULT_AFTER = 45000, TEEN_AFTER = 40000, CHILD_AFTER = 35000, BABY_AFTER = 15000;
		
	// 종합입장권 
	const int ADULT_DAY_TOTAL = 59000, TEEN_DAY_TOTAL = 52000, CHILD_DAY_TOTAL = 47000, BABY_DAY_TOTAL = 15000;
	const int ADULT_AFTER_TOTAL = 48000, TEEN_AFTER_TOTAL = 42000, CHILD_AFTER_TOTAL = 36000, BABY_AFTER_TOTAL = 15000;
		
	// 오늘 날짜 계산	
	struct tm *today;
	time_t timer;
	int year, month, day;
	time(&timer);
	
	today = localtime(&timer); 
	
	timer = time(NULL); 
	
	year = (today -> tm_year -100)*10000;
	month = (today -> tm_mon +1)*100;
	day = today -> tm_mday;
	
	int todayYMD = year + month + day;
		
	do{
		ticketSelect = 0, idNumber = 0, backIdNumber = 0, orderCount = 0, discount = 0, age = 0,
		price = 0, countPrice = 0, discountPrice = 0; // 변수초기화 
	
		//화면 출력 
		printf("************* COCOLAND ************* \n\t[오늘 날짜 : %d] \n\n", todayYMD);
		
		// 권종 선택 
		do{  
			printf(" 권종을 선택하세요.(After4는 오후 4시부터 입장) \n 1. 파크이용권 [1DAY]\n 2. 파크이용권 [After4]\n 3. 종합이용권 [1DAY]\n 4. 종합이용권 [After4]\n");
			scanf("%d", &ticketSelect);
			
			if(!(ticketSelect ==1 || ticketSelect ==2 || ticketSelect ==3 || ticketSelect ==4 )){
				printf("\n 잘못입력하셨습니다. 다시 입력해주세요.\n\n");
				}
				
		}while (!(ticketSelect ==1 || ticketSelect ==2 || ticketSelect ==3 || ticketSelect ==4 ));
	
		// 주민번호 입력 
		do{ 
			printf("\n 주민번호 앞 6글자를 입력하세요\n");
			scanf("%d", &idNumber);
			
			if(!((idNumber >= 000101) && (idNumber <= 991231))){
				printf("\n 잘못입력하셨습니다. 다시 입력해주세요.\n\n");
				}
				
		}while (!((idNumber >= 000101) && (idNumber <= 991231)));
		
		do{ 
			printf("\n 주민번호 뒤 1글자를 입력하세요\n");
			scanf("%d", &backIdNumber);
			if(!(backIdNumber ==1 || backIdNumber ==2 || backIdNumber ==3 || backIdNumber ==4 )){
				printf("\n 잘못입력하셨습니다. 다시 입력해주세요.\n\n");
				}
				
		}while(!(backIdNumber ==1 || backIdNumber ==2 || backIdNumber ==3 || backIdNumber ==4 ));
		
		// 갯수 입력 
		do{
			printf("\n 몇개를 주문하시겠습니까? (최대 10개) \n");
			scanf("%d", &orderCount);
			if(orderCount > 10){
					printf("\n 잘못입력하셨습니다. 다시 입력해주세요.\n\n");
				}
				
		}while(orderCount > 10);
			
		// 우대사항 입력 
		do{
			printf("\n 우대사항을 선택하세요. \n 1. 없음(나이 우대는 자동처리)\n 2. 장애인 \n 3. 국가유공자 \n 4. 휴가장병 \n 5. 임산부\n 6. 다둥이\n");
			scanf("%d", &discount);
			if(!(discount ==1 || discount ==2 || discount ==3 || discount ==4 || discount == 5 || discount == 6)){
				printf("\n 잘못입력하셨습니다. 다시 입력해주세요.\n\n");
			}
			
		}while (!(discount ==1 || discount ==2 || discount ==3 || discount ==4 || discount == 5 || discount == 6));
		
		// 만나이 계산 
		age = (todayYMD - (idNumber))/10000;
		
		if((backIdNumber == 1) || (backIdNumber == 2)){
			age = age + 100;
		} 
		
		// 나이별 가격 측정
		switch(ticketSelect){
			case 1 : 
				if(age < 1){
				price = FREE;								// 0 ~ 12개월 = 무료 
				} 
				else if((age >= 1) && (age < 3)){
					price = BABY_DAY;						// 12개월 이상 36개월 미만 = 베이비 요금  
				}
				else if((age >= 3) && (age < 13)){
					price = CHILD_DAY;						// 36개월 이상 ~ 만 12세  =어린이 요금 
				}
				else if((age >= 13) && (age < 18)){
					price = TEEN_DAY;						// 만 13세 ~ 18세 = 청소년 요금 
				}
				else if(age >= 65){
					price = CHILD_DAY;						// 만 65세 이상 = 어린이 요금 
				}
				else{
					price = ADULT_DAY;						// 나머지 = 어른 요금 
				} 
				break;
				
			case 2 :
				if(age < 1){
				price = FREE;								// 0 ~ 12개월 = 무료 
				} 
				else if((age >= 1) && (age < 3)){
					price = BABY_AFTER;						// 12개월 이상 36개월 미만 = 베이비 요금  
				}
				else if((age >= 3) && (age < 13)){
					price = CHILD_AFTER;					// 36개월 이상 ~ 만 12세 = 어린이 요금 
				}
				else if((age >= 13) && (age < 18)){
					price = TEEN_AFTER;						// 만 13세 ~ 18세 = 청소년 요금 
				}
				else if(age >= 65){
					price = CHILD_AFTER;					// 만 65세 이상 = 어린이 요금 
				}
				else{
					price = ADULT_AFTER;					// 나머지 = 어른 요금 
				}
				break;
				
			case 3 :
				if(age < 1){
				price = FREE;								// 0 ~ 12개월 = 무료 
				} 
				else if((age >= 1) && (age < 3)){
					price = BABY_DAY_TOTAL;					// 12개월 이상 36개월 미만 = 베이비 요금  
				}
				else if((age >= 3) && (age < 13)){
					price = CHILD_DAY_TOTAL;				// 36개월 이상 ~ 만 12세 = 어린이 요금 
				}
				else if((age >= 13) && (age < 18)){
					price = TEEN_DAY_TOTAL;					// 만 13세 ~ 18세 = 청소년 요금 
				}
				else if(age >= 65){
					price = CHILD_DAY_TOTAL;				// 만 65세 이상 = 어린이 요금 
				}
				else{
					price = ADULT_DAY_TOTAL;				// 나머지 = 어른 요금 
				} 
				break;
				
			case 4 :
				if(age < 1){
				price = FREE;								// 0 ~ 12개월 = 무료 
				} 
				else if((age >= 1) && (age < 3)){
					price = BABY_AFTER_TOTAL;				// 12개월 이상 36개월 미만 = 베이비 요금  
				}
				else if((age >= 3) && (age < 13)){
					price = CHILD_AFTER_TOTAL;				// 36개월 이상 ~ 만 12세 = 어린이 요금 
				}
				else if((age >= 13) && (age < 18)){
					price = TEEN_AFTER_TOTAL;				// 만 13세 ~ 18세 = 청소년 요금 
				}
				else if(age >= 65){
					price = CHILD_AFTER_TOTAL;				// 만 65세 이상 = 어린이 요금 
				}
				else{
					price = ADULT_AFTER_TOTAL;				// 나머지 = 어른 요금 
				}
				break;
		}
		
		
		// 주문 개수
		if(orderCount <= 10){
			countPrice = price * orderCount;
		}
		
		// 우대사항
		switch(discount){
			case 1 :										// 우대사항 없음 
				discountPrice = countPrice;
				break;
			
			case 2 :										// 장애인 50% 우대, 종합/파크  (+동반1인) 
				discountPrice = countPrice * 0.5;
				break;
			
			case 3 :										// 국가유공자 50% 우대, 종합/파크  (+동반1인)
				discountPrice = countPrice * 0.5;
				break;
				
			case 4 :										// 휴가장병 49% 우대, 종합  (+동반1인)
				discountPrice = countPrice;
				if((ticketSelect == 3) || (ticketSelect == 4)){
					discountPrice = countPrice * 0.51;
					}
				break;
			
			case 5 :										// 임산부 50% 우대, 종합
				discountPrice = countPrice;
				if((ticketSelect == 3) || (ticketSelect == 4)){
					discountPrice = countPrice * 0.5;
					}
				break;
				
			case 6 :										// 다둥이 30% 우대, 종합
				discountPrice = countPrice;
				if((ticketSelect == 3) || (ticketSelect == 4)){
					discountPrice = countPrice * 0.5;
					}
				break;		
			}
		
		printf("\n 가격은 %d원입니다. 감사합니다.\n", discountPrice);
		
		ticketSelectArr[index] = ticketSelect;
		orderCountArr[index] = orderCount;
		discountArr[index] = discount;
		discountPriceArr[index] = discountPrice;
		totalPrice += discountPrice;
		
		index++;
		
		printf("\n 계속 발권 하시겠습니까? \n1. 티켓 발권\n2. 종료\n");
		scanf("%d", &again);
		
	} while(again == 1);
	
	printf("\n COCOLAND를 이용해주셔서 감사합니다.\n");
		
	// 영수증 출력
	printf("\n\n************* COCOLAND *************\n");
	printf("   %s\t\t\t%s\t\t%s\n", "선택사항", "가격", "우대사항");
			
	for (int i = 0; i < index; i++) {
		switch (ticketSelectArr[i]) {
			case 1:
				printf("%s %5s","파크이용권","1Day");
				break;
			case 2:
				printf("%s %5s","파크이용권","After4");
				break;
			case 3:						
				printf("%s %5s","종합이용권","1Day");
				break;
			case 4:
				printf("%s %5s","종합이용권","After4");
				break;
			default:
				break;
			}
				
		printf(" x %d 매\t\t%d원\t\t",orderCountArr[i], discountPriceArr[i]) ;
				
		switch (discountArr[i]) {
			case 1:
				printf("%s\n","없음");
				break;
			case 2:
				printf("%s\n","장애인 우대");
				break;
			case 3:
				printf("%s\n","국가유공자 우대");
				break;
			case 4:
				printf("%s\n","휴가장병 우대");
				break;
			case 5:
				printf("%s\n","임산부 우대");
				break;
			case 6:
				printf("%s\n","다둥이 행복카드 우대");
				break;
			default:
				break;
				}
			}
		
	printf("\n입장료 총액은 %d원 입니다.", totalPrice);
	printf("\n=====================================================================================\n") ;
	
	return 0;
}
