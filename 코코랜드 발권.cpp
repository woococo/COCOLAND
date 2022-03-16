#include<stdio.h>
#include <time.h>

int main()
{
	int ticketSelect, orderCount, discount;
	long long int idNumber;	

	//화면 출력 	
	printf("권종을 선택하세요. \n1. 1DAY \n2. After4(오후 4시부터 입장)\n3. 1DAY(종합이용권) \n4. After4(종합이용권, 오후 4시부터 입장)\n");
	scanf("%d", &ticketSelect);
	
	printf("주민번호를 입력하세요\n");
	scanf("%lld", &idNumber);
	
	printf("몇개를 주문하시겠습니까? (최대 10개) \n");
	scanf("%d", &orderCount);
	
	printf("우대사항을 선택하세요. \n1. 없음(나이 우대는 자동처리)\n2. 장애인 \n3. 국가유공자 \n4. 휴가장병 \n5. 임산부\n6. 다둥이\n");
	scanf("%d", &discount);
	
	// 파크입장권 
	const int adultDayPrice = 56000, teenDayPrice = 50000, childDayPrice = 46000, babyDayPrice = 15000, freeDayPrice = 0;
	const int adultAfterPrice = 45000, teenAfterPrice = 40000, childAfterPrice = 35000, babyAfterPrice = 15000, freeAfterPrice = 0;
	
	// 종합입장권 
	const int adultDayTotalPrice = 59000, teenDayTotalPrice = 52000, childDayTotalPrice = 47000, babyDayTotalPrice = 15000, freeDayTotalPrice = 0;
	const int adultAfterTotalPrice = 48000, teenAfterTotalPrice = 42000, childAfterTotalPrice = 36000, babyAfterTotalPrice = 15000, freeAfterTotalPrice = 0;
	
	// 현재 날짜 계산	
	struct tm *today;
	time_t timer;
	int year, month, day;
	time(&timer);
	
	today = localtime(&timer); // 초 단위의 시간을 분리하여 구조체에 넣기
	
	timer = time(NULL); // 현재 시각을 초 단위로 얻기

	year = (today -> tm_year -100)*10000;
	month = (today -> tm_mon +1)*100;
	day = today -> tm_mday;
	
	int todayYMD = year + month + day;
	
	// 만나이 계산 
	int age, generation;
	
	age = (todayYMD - (idNumber/10000000))/10000;
	
	if(((idNumber % 10000000) >= 1000000) && ((idNumber % 10000000) < 2000000 )){
		generation = 1;		// 주민번호 뒷자리 첫번째가 1 
	}
	else if(((idNumber % 10000000) >= 2000000) && ((idNumber % 10000000) < 3000000 )){
		generation = 2;		// 주민번호 뒷자리 첫번째가 2
	}
	else if(((idNumber % 10000000) >= 3000000) && ((idNumber % 10000000) < 4000000 )){
		generation = 3;		// 주민번호 뒷자리 첫번째가 3
	}
	else if(((idNumber % 10000000) >= 4000000) && ((idNumber % 10000000) < 5000000 )){
		generation = 4;		// 주민번호 뒷자리 첫번째가 4
	}
	
	if((generation == 1) || (generation == 2)){
		age = age + 100;
	} 
	
	int price = 0;
	
	if(ticketSelect == 1){ 	// 파크 이용권 DAY 선택  
		if(age < 1){
			price = freeDayPrice;	// 0 ~ 12개월 베이비는 무료 
		} 
		else if((age >= 1) && (age < 3)){
			price = childDayPrice;	// 12개월 이상 36개월 미만 베이비 요금  
		}
		else if((age >= 3) && (age < 13)){
			price = childDayPrice;	// 36개월 이상 ~ 만 12세 어린이 요금 
		}
		else if((age >= 13) && (age < 18)){
			price = teenDayPrice;	// 만 13세 ~ 18세 청소년 요금 
		}
		else if(age >= 65){
			price = childDayPrice;	// 만 65세 이상 = 어린이 요금 
		}
		else{
			price = adultDayPrice;	// 나머지 어른 요금 
		} 
		
	}
	
	else if(ticketSelect == 2){	// 파크 이용권 After4 선택 
		if(age < 1){
			price = freeAfterPrice;	// 0 ~ 12개월 베이비는 무료 
		} 
		else if((age >= 1) && (age < 3)){
			price = childAfterPrice;	// 12개월 이상 36개월 미만 베이비 요금  
		}
		else if((age >= 3) && (age < 13)){
			price = childAfterPrice;	// 36개월 이상 ~ 만 12세 어린이 요금 
		}
		else if((age >= 13) && (age < 18)){
			price = teenAfterPrice;	// 만 13세 ~ 18세 청소년 요금 
		}
		else if(age >= 65){
			price = childAfterPrice;	// 만 65세 이상 = 어린이 요금 
		}
		else{
			price = adultAfterPrice;	// 나머지 어른 요금 
		}
	}
	
	if(ticketSelect == 3){ 	// 종합이용권 Day 선택 
		if(age < 1){
			price = freeDayTotalPrice;	// 0 ~ 12개월 베이비는 무료 
		} 
		else if((age >= 1) && (age < 3)){
			price = childDayTotalPrice;	// 12개월 이상 36개월 미만 베이비 요금  
		}
		else if((age >= 3) && (age < 13)){
			price = childDayTotalPrice;	// 36개월 이상 ~ 만 12세 어린이 요금 
		}
		else if((age >= 13) && (age < 18)){
			price = teenDayTotalPrice;	// 만 13세 ~ 18세 청소년 요금 
		}
		else if(age >= 65){
			price = childDayTotalPrice;	// 만 65세 이상 = 어린이 요금 
		}
		else{
			price = adultDayTotalPrice;	// 나머지 어른 요금 
		} 
		
	}
	
	else if(ticketSelect == 4){	// 종합이용권 After4 선택 
		if(age < 1){
			price = freeAfterTotalPrice;	// 0 ~ 12개월 베이비는 무료 
		} 
		else if((age >= 1) && (age < 3)){
			price = childAfterTotalPrice;	// 12개월 이상 36개월 미만 베이비 요금  
		}
		else if((age >= 3) && (age < 13)){
			price = childAfterTotalPrice;	// 36개월 이상 ~ 만 12세 어린이 요금 
		}
		else if((age >= 13) && (age < 18)){
			price = teenAfterTotalPrice;	// 만 13세 ~ 18세 청소년 요금 
		}
		else if(age >= 65){
			price = childAfterTotalPrice;	// 만 65세 이상 = 어린이 요금 
		}
		else{
			price = adultAfterTotalPrice;	// 나머지 어른 요금 
		}
	}
	
	// 주문 개수
	if(orderCount <= 10){
		price = price * orderCount;
	}
	else{
		printf("잘못입력하셨습니다.\n");
	}
	
	// 우대사항
	if(discount == 2){
		price = price * 0.5;	// 장애인 50% 우대, 종합/파크  (+동반1인) 
	}
	 
	if(discount == 3){
		price = price * 0.5;	// 국가유공자 50% 우대, 종합/파크  (+동반1인) 
	} 
	
	if(((ticketSelect == 3) || (ticketSelect == 4)) && (discount == 4)){ 
		price = price * 0.49;	// 휴가장병 49% 우대, 종합  (+동반1인) 
	} 
	 
	if(((ticketSelect == 3) || (ticketSelect == 4)) && (discount == 5)){
		price = price * 0.5;	// 임산부 50% 우대, 종합 
	} 
		
	if(((ticketSelect == 3) || (ticketSelect == 4)) && (discount == 6)){
		price = price * 0.3;	// 다둥이 30% 우대, 종합 
	} 	
	 
	printf("가격은 %d원입니다.\n감사합니다.\n", price);

	return 0;
}
