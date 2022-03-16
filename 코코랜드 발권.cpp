#include<stdio.h>
#include <time.h>

int main()
{
	int ticketSelect, orderCount, discount;
	long long int idNumber;	

	//ȭ�� ��� 	
	printf("������ �����ϼ���. \n1. 1DAY \n2. After4(���� 4�ú��� ����)\n3. 1DAY(�����̿��) \n4. After4(�����̿��, ���� 4�ú��� ����)\n");
	scanf("%d", &ticketSelect);
	
	printf("�ֹι�ȣ�� �Է��ϼ���\n");
	scanf("%lld", &idNumber);
	
	printf("��� �ֹ��Ͻðڽ��ϱ�? (�ִ� 10��) \n");
	scanf("%d", &orderCount);
	
	printf("�������� �����ϼ���. \n1. ����(���� ���� �ڵ�ó��)\n2. ����� \n3. ���������� \n4. �ް��庴 \n5. �ӻ��\n6. �ٵ���\n");
	scanf("%d", &discount);
	
	// ��ũ����� 
	const int adultDayPrice = 56000, teenDayPrice = 50000, childDayPrice = 46000, babyDayPrice = 15000, freeDayPrice = 0;
	const int adultAfterPrice = 45000, teenAfterPrice = 40000, childAfterPrice = 35000, babyAfterPrice = 15000, freeAfterPrice = 0;
	
	// ��������� 
	const int adultDayTotalPrice = 59000, teenDayTotalPrice = 52000, childDayTotalPrice = 47000, babyDayTotalPrice = 15000, freeDayTotalPrice = 0;
	const int adultAfterTotalPrice = 48000, teenAfterTotalPrice = 42000, childAfterTotalPrice = 36000, babyAfterTotalPrice = 15000, freeAfterTotalPrice = 0;
	
	// ���� ��¥ ���	
	struct tm *today;
	time_t timer;
	int year, month, day;
	time(&timer);
	
	today = localtime(&timer); // �� ������ �ð��� �и��Ͽ� ����ü�� �ֱ�
	
	timer = time(NULL); // ���� �ð��� �� ������ ���

	year = (today -> tm_year -100)*10000;
	month = (today -> tm_mon +1)*100;
	day = today -> tm_mday;
	
	int todayYMD = year + month + day;
	
	// ������ ��� 
	int age, generation;
	
	age = (todayYMD - (idNumber/10000000))/10000;
	
	if(((idNumber % 10000000) >= 1000000) && ((idNumber % 10000000) < 2000000 )){
		generation = 1;		// �ֹι�ȣ ���ڸ� ù��°�� 1 
	}
	else if(((idNumber % 10000000) >= 2000000) && ((idNumber % 10000000) < 3000000 )){
		generation = 2;		// �ֹι�ȣ ���ڸ� ù��°�� 2
	}
	else if(((idNumber % 10000000) >= 3000000) && ((idNumber % 10000000) < 4000000 )){
		generation = 3;		// �ֹι�ȣ ���ڸ� ù��°�� 3
	}
	else if(((idNumber % 10000000) >= 4000000) && ((idNumber % 10000000) < 5000000 )){
		generation = 4;		// �ֹι�ȣ ���ڸ� ù��°�� 4
	}
	
	if((generation == 1) || (generation == 2)){
		age = age + 100;
	} 
	
	int price = 0;
	
	if(ticketSelect == 1){ 	// ��ũ �̿�� DAY ����  
		if(age < 1){
			price = freeDayPrice;	// 0 ~ 12���� ���̺�� ���� 
		} 
		else if((age >= 1) && (age < 3)){
			price = childDayPrice;	// 12���� �̻� 36���� �̸� ���̺� ���  
		}
		else if((age >= 3) && (age < 13)){
			price = childDayPrice;	// 36���� �̻� ~ �� 12�� ��� ��� 
		}
		else if((age >= 13) && (age < 18)){
			price = teenDayPrice;	// �� 13�� ~ 18�� û�ҳ� ��� 
		}
		else if(age >= 65){
			price = childDayPrice;	// �� 65�� �̻� = ��� ��� 
		}
		else{
			price = adultDayPrice;	// ������ � ��� 
		} 
		
	}
	
	else if(ticketSelect == 2){	// ��ũ �̿�� After4 ���� 
		if(age < 1){
			price = freeAfterPrice;	// 0 ~ 12���� ���̺�� ���� 
		} 
		else if((age >= 1) && (age < 3)){
			price = childAfterPrice;	// 12���� �̻� 36���� �̸� ���̺� ���  
		}
		else if((age >= 3) && (age < 13)){
			price = childAfterPrice;	// 36���� �̻� ~ �� 12�� ��� ��� 
		}
		else if((age >= 13) && (age < 18)){
			price = teenAfterPrice;	// �� 13�� ~ 18�� û�ҳ� ��� 
		}
		else if(age >= 65){
			price = childAfterPrice;	// �� 65�� �̻� = ��� ��� 
		}
		else{
			price = adultAfterPrice;	// ������ � ��� 
		}
	}
	
	if(ticketSelect == 3){ 	// �����̿�� Day ���� 
		if(age < 1){
			price = freeDayTotalPrice;	// 0 ~ 12���� ���̺�� ���� 
		} 
		else if((age >= 1) && (age < 3)){
			price = childDayTotalPrice;	// 12���� �̻� 36���� �̸� ���̺� ���  
		}
		else if((age >= 3) && (age < 13)){
			price = childDayTotalPrice;	// 36���� �̻� ~ �� 12�� ��� ��� 
		}
		else if((age >= 13) && (age < 18)){
			price = teenDayTotalPrice;	// �� 13�� ~ 18�� û�ҳ� ��� 
		}
		else if(age >= 65){
			price = childDayTotalPrice;	// �� 65�� �̻� = ��� ��� 
		}
		else{
			price = adultDayTotalPrice;	// ������ � ��� 
		} 
		
	}
	
	else if(ticketSelect == 4){	// �����̿�� After4 ���� 
		if(age < 1){
			price = freeAfterTotalPrice;	// 0 ~ 12���� ���̺�� ���� 
		} 
		else if((age >= 1) && (age < 3)){
			price = childAfterTotalPrice;	// 12���� �̻� 36���� �̸� ���̺� ���  
		}
		else if((age >= 3) && (age < 13)){
			price = childAfterTotalPrice;	// 36���� �̻� ~ �� 12�� ��� ��� 
		}
		else if((age >= 13) && (age < 18)){
			price = teenAfterTotalPrice;	// �� 13�� ~ 18�� û�ҳ� ��� 
		}
		else if(age >= 65){
			price = childAfterTotalPrice;	// �� 65�� �̻� = ��� ��� 
		}
		else{
			price = adultAfterTotalPrice;	// ������ � ��� 
		}
	}
	
	// �ֹ� ����
	if(orderCount <= 10){
		price = price * orderCount;
	}
	else{
		printf("�߸��Է��ϼ̽��ϴ�.\n");
	}
	
	// ������
	if(discount == 2){
		price = price * 0.5;	// ����� 50% ���, ����/��ũ  (+����1��) 
	}
	 
	if(discount == 3){
		price = price * 0.5;	// ���������� 50% ���, ����/��ũ  (+����1��) 
	} 
	
	if(((ticketSelect == 3) || (ticketSelect == 4)) && (discount == 4)){ 
		price = price * 0.49;	// �ް��庴 49% ���, ����  (+����1��) 
	} 
	 
	if(((ticketSelect == 3) || (ticketSelect == 4)) && (discount == 5)){
		price = price * 0.5;	// �ӻ�� 50% ���, ���� 
	} 
		
	if(((ticketSelect == 3) || (ticketSelect == 4)) && (discount == 6)){
		price = price * 0.3;	// �ٵ��� 30% ���, ���� 
	} 	
	 
	printf("������ %d���Դϴ�.\n�����մϴ�.\n", price);

	return 0;
}
