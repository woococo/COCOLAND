#include<stdio.h>
#include <time.h>

int main()
{
	for(;;){
	
		// 현재 날짜 계산	
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
		
		//화면 출력 
		printf("\n[오늘 날짜 : %d] \n\n", todayYMD);
	
		int ticketSelect, idNumber, backIdNumber, orderCount, discount;	
			
		// 권종 선택 
		do{  
			printf("권종을 선택하세요. \n1. 1DAY \n2. After4(오후 4시부터 입장)\n3. 1DAY(종합이용권) \n4. After4(종합이용권, 오후 4시부터 입장)\n");
			scanf("%d", &ticketSelect);
			if(!(ticketSelect ==1 || ticketSelect ==2 || ticketSelect ==3 || ticketSelect ==4 )){
				printf("\n잘못입력하셨습니다. 다시 입력해주세요.\n\n");
				}
		}while (!(ticketSelect ==1 || ticketSelect ==2 || ticketSelect ==3 || ticketSelect ==4 ));
	
	
		// 주민번호 입력 
		do{ 
			printf("\n주민번호 앞 6글자를 입력하세요\n");
			scanf("%d", &idNumber);
			if(!((idNumber >= 000101) && (idNumber <= 991231))){
				printf("\n잘못입력하셨습니다. 다시 입력해주세요.\n\n");
				}
		}while (!((idNumber >= 000101) && (idNumber <= 991231)));
		
		do{ 
			printf("\n주민번호 뒤 1글자를 입력하세요\n");
			scanf("%d", &backIdNumber);
			if(!(backIdNumber ==1 || backIdNumber ==2 || backIdNumber ==3 || backIdNumber ==4 )){
				printf("\n잘못입력하셨습니다. 다시 입력해주세요.\n\n");
				}
		}while(!(backIdNumber ==1 || backIdNumber ==2 || backIdNumber ==3 || backIdNumber ==4 ));
		
		// 갯수 입력 
		do{
			printf("\n몇개를 주문하시겠습니까? (최대 10개) \n");
			scanf("%d", &orderCount);
			if(orderCount > 10){
					printf("\n잘못입력하셨습니다. 다시 입력해주세요.\n\n");
				}
		}while(orderCount > 10);
			
		// 우대사항 입력 
		do{
			printf("\n우대사항을 선택하세요. \n1. 없음(나이 우대는 자동처리)\n2. 장애인 \n3. 국가유공자 \n4. 휴가장병 \n5. 임산부\n6. 다둥이\n");
			scanf("%d", &discount);
			if(!(discount ==1 || discount ==2 || discount ==3 || discount ==4 || discount == 5 || discount == 6)){
				printf("\n잘못입력하셨습니다. 다시 입력해주세요.\n\n");
			}
		}while (!(discount ==1 || discount ==2 || discount ==3 || discount ==4 || discount == 5 || discount == 6));
		
		// 파크입장권 (상수는 대문자로 할 것!) 
		const int ADULTDAYPRICE = 56000, TEENDAYPRICE = 50000, CHILDDAYPRICE = 46000, BABYDAYPRICE = 15000, FREE = 0;
		const int ADULTAFTERPRICE = 45000, TEENAFTERPRICE = 40000, CHILDAFTERPRICE = 35000, BABYAFTERPRICE = 15000;
		
		// 종합입장권 
		const int ADULTDAYTOTALPRICE = 59000, TEENDAYTOTALPRICE = 52000, CHILDDAYTOTALPRICE = 47000, BABYDAYTOTALPRICE = 15000;
		const int ADULTAFTERTOTALPRICE = 48000, TEENAFTERTOTALPRICE = 42000, CHILDAFTERTOTALPRICE = 36000, BABYAFTERTOTALPRICE = 15000;
		
		// 만나이 계산 
		int age = (todayYMD - (idNumber))/10000;
		
		if((backIdNumber == 1) || (backIdNumber == 2)){
			age = age + 100;
		} 
		
		// 나이별 가격 측정
		int price = 0;
		 
		switch(ticketSelect){
			case 1 : 
				if(age < 1){
				price = FREE;	// 0 ~ 12개월 베이비는 무료 
				} 
				else if((age >= 1) && (age < 3)){
					price = BABYDAYPRICE;	// 12개월 이상 36개월 미만 베이비 요금  
				}
				else if((age >= 3) && (age < 13)){
					price = CHILDDAYPRICE;	// 36개월 이상 ~ 만 12세 어린이 요금 
				}
				else if((age >= 13) && (age < 18)){
					price = TEENDAYPRICE;	// 만 13세 ~ 18세 청소년 요금 
				}
				else if(age >= 65){
					price = CHILDDAYPRICE;	// 만 65세 이상 = 어린이 요금 
				}
				else{
					price = ADULTDAYPRICE;	// 나머지 어른 요금 
				} 
				
			case 2 :
				if(age < 1){
				price = FREE;	// 0 ~ 12개월 베이비는 무료 
				} 
				else if((age >= 1) && (age < 3)){
					price = BABYAFTERPRICE;	// 12개월 이상 36개월 미만 베이비 요금  
				}
				else if((age >= 3) && (age < 13)){
					price = CHILDAFTERPRICE;	// 36개월 이상 ~ 만 12세 어린이 요금 
				}
				else if((age >= 13) && (age < 18)){
					price = TEENAFTERPRICE;	// 만 13세 ~ 18세 청소년 요금 
				}
				else if(age >= 65){
					price = CHILDAFTERPRICE;	// 만 65세 이상 = 어린이 요금 
				}
				else{
					price = ADULTAFTERPRICE;	// 나머지 어른 요금 
				}
				
			case 3 :
				if(age < 1){
				price = FREE;	// 0 ~ 12개월 베이비는 무료 
				} 
				else if((age >= 1) && (age < 3)){
					price = BABYDAYTOTALPRICE;	// 12개월 이상 36개월 미만 베이비 요금  
				}
				else if((age >= 3) && (age < 13)){
					price = CHILDDAYTOTALPRICE;	// 36개월 이상 ~ 만 12세 어린이 요금 
				}
				else if((age >= 13) && (age < 18)){
					price = TEENDAYTOTALPRICE;	// 만 13세 ~ 18세 청소년 요금 
				}
				else if(age >= 65){
					price = CHILDDAYTOTALPRICE;	// 만 65세 이상 = 어린이 요금 
				}
				else{
					price = ADULTDAYTOTALPRICE;	// 나머지 어른 요금 
				} 
				
			case 4 :
				if(age < 1){
				price = FREE;	// 0 ~ 12개월 베이비는 무료 
				} 
				else if((age >= 1) && (age < 3)){
					price = BABYAFTERTOTALPRICE;	// 12개월 이상 36개월 미만 베이비 요금  
				}
				else if((age >= 3) && (age < 13)){
					price = CHILDAFTERTOTALPRICE;	// 36개월 이상 ~ 만 12세 어린이 요금 
				}
				else if((age >= 13) && (age < 18)){
					price = TEENAFTERTOTALPRICE;	// 만 13세 ~ 18세 청소년 요금 
				}
				else if(age >= 65){
					price = CHILDAFTERTOTALPRICE;	// 만 65세 이상 = 어린이 요금 
				}
				else{
					price = ADULTAFTERTOTALPRICE;	// 나머지 어른 요금 
				}
		}
		
		// 주문 개수
		if(orderCount <= 10){
			price = price * orderCount;
		}
		
		// 우대사항
		switch(discount){
			case 1 :					// 우대사항 없음 
				price = price;
				break;
			
			case 2 :					// 장애인 50% 우대, 종합/파크  (+동반1인) 
				price = price * 0.5;
				break;
			
			case 3 :					// 국가유공자 50% 우대, 종합/파크  (+동반1인)
				price = price * 0.5;
				break;
				
			case 4 :					// 휴가장병 49% 우대, 종합  (+동반1인)
				price = price;
				if((ticketSelect == 3) || (ticketSelect == 4)){
					price = price * 0.51;
					}
				break;
			
			case 5 :					// 임산부 50% 우대, 종합
				price = price;
				if((ticketSelect == 3) || (ticketSelect == 4)){
					price = price * 0.5;
					}
				break;
				
			case 6 :					// 다둥이 30% 우대, 종합
				price = price;
				if((ticketSelect == 3) || (ticketSelect == 4)){
					price = price * 0.5;
					}
				break;		
			}
		
		printf("\n가격은 %d원입니다. 감사합니다.\n", price);
		
		int again;
		
		printf("\n계속 발권 하시겠습니까? \n1. 티켓 발권\n2. 종료\n");
		scanf("%d", &again);
		if(again == 2 ){
			break; 
		}
	
	}
	return 0;
}
