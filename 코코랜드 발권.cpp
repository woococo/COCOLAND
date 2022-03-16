#include<stdio.h>

int main()
{
	int choice1, choice3, choice4;
	long long int choice2;	

	//ȭ�� ��� 	
	printf("������ �����ϼ���. \n1. 1DAY \n2. After4(���� 4�ú��� ����)\n3. 1DAY(�����̿��) \n4. After4(�����̿��, ���� 4�ú��� ����)\n");
	scanf("%d", &choice1);
	
	printf("�ֹι�ȣ�� �Է��ϼ���\n");
	scanf("%lld", &choice2);
	
	printf("��� �ֹ��Ͻðڽ��ϱ�? (�ִ� 10��) \n");
	scanf("%d", &choice3);
	
	printf("�������� �����ϼ���. \n1. ����(���� ���� �ڵ�ó��)\n2. ����� \n3. ���������� \n4. �ް��庴 \n5. �ӻ��\n6. �ٵ���\n");
	scanf("%d", &choice4);
	
	// ��ũ����� 
	const int adultDayPrice = 56000, teenDayPrice = 50000, childDayPrice = 46000, babyDayPrice = 15000, freeDayPrice = 0;
	const int adultAfterPrice = 45000, teenAfterPrice = 40000, childAfterPrice = 35000, babyAfterPrice = 15000, freeAfterPrice = 0;
	
	// ��������� 
	const int adultDayTotalPrice = 59000, teenDayTotalPrice = 52000, childDayTotalPrice = 47000, babyDayTotalPrice = 15000, freeDayTotalPrice = 0;
	const int adultAfterTotalPrice = 48000, teenAfterTotalPrice = 42000, childAfterTotalPrice = 36000, babyAfterTotalPrice = 15000, freeAfterTotalPrice = 0;
	
	// �� ���� ��� 
	long int todayYMD = 220316;	// ���ó�¥�Է� 
	int age, generation;
	
	age = (todayYMD - (choice2/10000000))/10000;
	
	if(((choice2 % 10000000) >= 1000000) && ((choice2 % 10000000) < 2000000 )){
		generation = 1;		// �ֹι�ȣ ���ڸ� ù��°�� 1 
	}
	else if(((choice2 % 10000000) >= 2000000) && ((choice2 % 10000000) < 3000000 )){
		generation = 2;		// �ֹι�ȣ ���ڸ� ù��°�� 2
	}
	else if(((choice2 % 10000000) >= 3000000) && ((choice2 % 10000000) < 4000000 )){
		generation = 3;		// �ֹι�ȣ ���ڸ� ù��°�� 3
	}
	else if(((choice2 % 10000000) >= 4000000) && ((choice2 % 10000000) < 5000000 )){
		generation = 4;		// �ֹι�ȣ ���ڸ� ù��°�� 4
	}
	
	if((generation == 1) || (generation == 2)){
		age = age + 100;
	} 
	
	int price = 0;
	
	if(choice1 == 1){ 	// ��ũ �̿�� DAY ����  
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
	
	else if(choice1 == 2){	// ��ũ �̿�� After4 ���� 
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
	
	if(choice1 == 3){ 	// �����̿�� Day ���� 
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
	
	else if(choice1 == 4){	// �����̿�� After4 ���� 
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
	if(choice3 <= 10){
		price = price * choice3;
	}
	else{
		printf("�߸��Է��ϼ̽��ϴ�.\n");
	}
	
	// ������
	if(choice4 == 2){
		price = price * 0.5;	// ����� 50% ���, ����/��ũ  (+����1��) 
	}
	 
	if(choice4 == 3){
		price = price * 0.5;	// ���������� 50% ���, ����/��ũ  (+����1��) 
	} 
	
	if(((choice1 == 3) || (choice1 == 4)) && (choice4 == 4)){ 
		price = price * 0.49;	// �ް��庴 49% ���, ����  (+����1��) 
	} 
	 
	if(((choice1 == 3) || (choice1 == 4)) && (choice4 == 5)){
		price = price * 0.5;	// �ӻ�� 50% ���, ���� 
	} 
		
	if(((choice1 == 3) || (choice1 == 4)) && (choice4 == 6)){
		price = price * 0.3;	// �ٵ��� 30% ���, ���� 
	} 	
	 
	printf("������ %d���Դϴ�.\n�����մϴ�.\n", price);
	
	return 0;
}
