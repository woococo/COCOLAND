#include<stdio.h>
#include <time.h>

int main()
{
	for(;;){
		
		int ticketSelect[10] = {0}, idNumber, backIdNumber, orderCount[10] = {0}, discount[10] = {0};	
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
		
		//화면 출력 
		printf("\n[오늘 날짜 : %d] \n\n", todayYMD);
		
		// 권종 선택 
		do{  
			printf("권종을 선택하세요. \n1. 1DAY \n2. After4(오후 4시부터 입장)\n3. 1DAY(종합이용권) \n4. After4(종합이용권, 오후 4시부터 입장)\n");
			scanf("%d", &ticketSelect[index]);
			if(!(ticketSelect[index] ==1 || ticketSelect[index] ==2 || ticketSelect[index] ==3 || ticketSelect[index] ==4 )){
				printf("\n잘못입력하셨습니다. 다시 입력해주세요.\n\n");
				}
		}while (!(ticketSelect[index] ==1 || ticketSelect[index] ==2 || ticketSelect[index] ==3 || ticketSelect[index] ==4 ));
	
	
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
			if(orderCount[index] > 10){
				printf("\n잘못입력하셨습니다. 다시 입력해주세요.\n\n");
				}
		}while(orderCount[index] > 10);
			
		// 우대사항 입력 
		do{
			printf("\n우대사항을 선택하세요. \n1. 없음(나이 우대는 자동처리)\n2. 장애인 \n3. 국가유공자 \n4. 휴가장병 \n5. 임산부\n6. 다둥이\n");
			scanf("%d", &discount);
			if(!(discount[index] ==1 || discount[index] ==2 || discount[index] ==3 || discount[index] ==4 || discount[index] == 5 || discount[index] == 6)){
				printf("\n잘못입력하셨습니다. 다시 입력해주세요.\n\n");
				}
		}while (!(discount[index] ==1 || discount[index] ==2 || discount[index] ==3 || discount[index] ==4 || discount[index] == 5 || discount[index] == 6));
		
		// 만나이 계산 
		int age = (todayYMD - (idNumber))/10000;
		
		if((backIdNumber == 1) || (backIdNumber == 2)){
			age = age + 100;
		} 
		
		// 나이별 가격 측정
		int price = 0;
	
		switch(ticketSelect[index]){
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
		if(orderCount[index] <= 10){
			price = price * orderCount[index];
		}
		
		// 우대사항
		switch(discount[index]){
			case 1 :										// 우대사항 없음 
				price = price;
				break;
			
			case 2 :										// 장애인 50% 우대, 종합/파크  (+동반1인) 
				price = price * 0.5;
				break;
			
			case 3 :										// 국가유공자 50% 우대, 종합/파크  (+동반1인)
				price = price * 0.5;
				break;
				
			case 4 :										// 휴가장병 49% 우대, 종합  (+동반1인)
				price = price;
				if((ticketSelect[index] == 3) || (ticketSelect[index] == 4)){
					price = price * 0.51;
					}
				break;
			
			case 5 :										// 임산부 50% 우대, 종합
				price = price;
				if((ticketSelect[index] == 3) || (ticketSelect[index] == 4)){
					price = price * 0.5;
					}
				break;
				
			case 6 :										// 다둥이 30% 우대, 종합
				price = price;
				if((ticketSelect[index] == 3) || (ticketSelect[index] == 4)){
					price = price * 0.5;
					}
				break;		
			}
		
		printf("\n가격은 %d원입니다. 감사합니다.\n", price);
	
		int again;
		
		do{
			printf("\n계속 발권 하시겠습니까? \n1. 티켓 발권\n2. 종료\n");
			scanf("%d", &again);
			if(!(again ==1 || again ==2)){
				printf("\n잘못입력하셨습니다. 다시 입력해주세요.\n\n");
			}
			index++;
		}while (!(again ==1 || again ==2));
		
		
				
		if(again == 2 ){
			printf("\n========== COCO LAND ===========\n");
			
			for(int i = 0; i <= index; i++){
				if(ticketSelect[i] == 1){
					printf("1DAY");}
				else if(ticketSelect[i] == 2){
					printf("After4");}
				else if(ticketSelect[i] == 3){
					printf("1DAY(종합이용권)");}
				else if(ticketSelect[i] == 4){
					printf("After4(종합이용권)");}
				
				printf(" ");
				
				if(age < 1){
					printf("무료");}
				else if((age >= 1) && (age < 3)){
					printf("베이비");}
				else if((age >= 3) && (age < 13)){
					printf("어린이");}
				else if((age >= 13) && (age < 18)){
					printf("청소년");}
				else if(age >= 65){
					printf("노인");}
				else{printf("어른");}
			
				printf("\tX %d개", orderCount[index]);
				printf("\t%d원", price);
				printf("\t*우대사항 : ");
				
				if(discount[i] == 1){
					printf("우대적용없음");
				}
				else if(discount[i] == 2){
					printf("장애인 50% 할인");
				} 
				else if(discount[i] == 3){
					printf("국가유공자 50% 할인");
				}
				else if(discount[i] == 4){
					printf("휴가장병 49% 할인");
				}
				else if(discount[i] == 5){
					printf("임산부 50% 할인");
				}
				else if(discount[i] == 6){
					printf("다둥이 30% 할인");
				}
				
			printf("\n"); 
				 
			}
			int totalPrice;
			for(int k = 0; k < index; k++){
				totalPrice += price;
			}
			printf("입장료 총액은 %d입니다.", totalPrice);
			
			break;
		}
	
}
	return 0;
}
