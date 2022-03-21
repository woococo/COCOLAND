#include<stdio.h>
#include <time.h>

int main()
{
	for(;;){
	
		// ���� ��¥ ���	
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
		
		//ȭ�� ��� 
		printf("\n[���� ��¥ : %d] \n\n", todayYMD);
	
		int ticketSelect, idNumber, backIdNumber, orderCount, discount;	
			
		// ���� ���� 
		do{  
			printf("������ �����ϼ���. \n1. 1DAY \n2. After4(���� 4�ú��� ����)\n3. 1DAY(�����̿��) \n4. After4(�����̿��, ���� 4�ú��� ����)\n");
			scanf("%d", &ticketSelect);
			if(!(ticketSelect ==1 || ticketSelect ==2 || ticketSelect ==3 || ticketSelect ==4 )){
				printf("\n�߸��Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.\n\n");
				}
		}while (!(ticketSelect ==1 || ticketSelect ==2 || ticketSelect ==3 || ticketSelect ==4 ));
	
	
		// �ֹι�ȣ �Է� 
		do{ 
			printf("\n�ֹι�ȣ �� 6���ڸ� �Է��ϼ���\n");
			scanf("%d", &idNumber);
			if(!((idNumber >= 000101) && (idNumber <= 991231))){
				printf("\n�߸��Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.\n\n");
				}
		}while (!((idNumber >= 000101) && (idNumber <= 991231)));
		
		do{ 
			printf("\n�ֹι�ȣ �� 1���ڸ� �Է��ϼ���\n");
			scanf("%d", &backIdNumber);
			if(!(backIdNumber ==1 || backIdNumber ==2 || backIdNumber ==3 || backIdNumber ==4 )){
				printf("\n�߸��Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.\n\n");
				}
		}while(!(backIdNumber ==1 || backIdNumber ==2 || backIdNumber ==3 || backIdNumber ==4 ));
		
		// ���� �Է� 
		do{
			printf("\n��� �ֹ��Ͻðڽ��ϱ�? (�ִ� 10��) \n");
			scanf("%d", &orderCount);
			if(orderCount > 10){
					printf("\n�߸��Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.\n\n");
				}
		}while(orderCount > 10);
			
		// ������ �Է� 
		do{
			printf("\n�������� �����ϼ���. \n1. ����(���� ���� �ڵ�ó��)\n2. ����� \n3. ���������� \n4. �ް��庴 \n5. �ӻ��\n6. �ٵ���\n");
			scanf("%d", &discount);
			if(!(discount ==1 || discount ==2 || discount ==3 || discount ==4 || discount == 5 || discount == 6)){
				printf("\n�߸��Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.\n\n");
			}
		}while (!(discount ==1 || discount ==2 || discount ==3 || discount ==4 || discount == 5 || discount == 6));
		
		// ��ũ����� (����� �빮�ڷ� �� ��!) 
		const int ADULTDAYPRICE = 56000, TEENDAYPRICE = 50000, CHILDDAYPRICE = 46000, BABYDAYPRICE = 15000, FREE = 0;
		const int ADULTAFTERPRICE = 45000, TEENAFTERPRICE = 40000, CHILDAFTERPRICE = 35000, BABYAFTERPRICE = 15000;
		
		// ��������� 
		const int ADULTDAYTOTALPRICE = 59000, TEENDAYTOTALPRICE = 52000, CHILDDAYTOTALPRICE = 47000, BABYDAYTOTALPRICE = 15000;
		const int ADULTAFTERTOTALPRICE = 48000, TEENAFTERTOTALPRICE = 42000, CHILDAFTERTOTALPRICE = 36000, BABYAFTERTOTALPRICE = 15000;
		
		// ������ ��� 
		int age = (todayYMD - (idNumber))/10000;
		
		if((backIdNumber == 1) || (backIdNumber == 2)){
			age = age + 100;
		} 
		
		// ���̺� ���� ����
		int price = 0;
		 
		switch(ticketSelect){
			case 1 : 
				if(age < 1){
				price = FREE;	// 0 ~ 12���� ���̺�� ���� 
				} 
				else if((age >= 1) && (age < 3)){
					price = BABYDAYPRICE;	// 12���� �̻� 36���� �̸� ���̺� ���  
				}
				else if((age >= 3) && (age < 13)){
					price = CHILDDAYPRICE;	// 36���� �̻� ~ �� 12�� ��� ��� 
				}
				else if((age >= 13) && (age < 18)){
					price = TEENDAYPRICE;	// �� 13�� ~ 18�� û�ҳ� ��� 
				}
				else if(age >= 65){
					price = CHILDDAYPRICE;	// �� 65�� �̻� = ��� ��� 
				}
				else{
					price = ADULTDAYPRICE;	// ������ � ��� 
				} 
				
			case 2 :
				if(age < 1){
				price = FREE;	// 0 ~ 12���� ���̺�� ���� 
				} 
				else if((age >= 1) && (age < 3)){
					price = BABYAFTERPRICE;	// 12���� �̻� 36���� �̸� ���̺� ���  
				}
				else if((age >= 3) && (age < 13)){
					price = CHILDAFTERPRICE;	// 36���� �̻� ~ �� 12�� ��� ��� 
				}
				else if((age >= 13) && (age < 18)){
					price = TEENAFTERPRICE;	// �� 13�� ~ 18�� û�ҳ� ��� 
				}
				else if(age >= 65){
					price = CHILDAFTERPRICE;	// �� 65�� �̻� = ��� ��� 
				}
				else{
					price = ADULTAFTERPRICE;	// ������ � ��� 
				}
				
			case 3 :
				if(age < 1){
				price = FREE;	// 0 ~ 12���� ���̺�� ���� 
				} 
				else if((age >= 1) && (age < 3)){
					price = BABYDAYTOTALPRICE;	// 12���� �̻� 36���� �̸� ���̺� ���  
				}
				else if((age >= 3) && (age < 13)){
					price = CHILDDAYTOTALPRICE;	// 36���� �̻� ~ �� 12�� ��� ��� 
				}
				else if((age >= 13) && (age < 18)){
					price = TEENDAYTOTALPRICE;	// �� 13�� ~ 18�� û�ҳ� ��� 
				}
				else if(age >= 65){
					price = CHILDDAYTOTALPRICE;	// �� 65�� �̻� = ��� ��� 
				}
				else{
					price = ADULTDAYTOTALPRICE;	// ������ � ��� 
				} 
				
			case 4 :
				if(age < 1){
				price = FREE;	// 0 ~ 12���� ���̺�� ���� 
				} 
				else if((age >= 1) && (age < 3)){
					price = BABYAFTERTOTALPRICE;	// 12���� �̻� 36���� �̸� ���̺� ���  
				}
				else if((age >= 3) && (age < 13)){
					price = CHILDAFTERTOTALPRICE;	// 36���� �̻� ~ �� 12�� ��� ��� 
				}
				else if((age >= 13) && (age < 18)){
					price = TEENAFTERTOTALPRICE;	// �� 13�� ~ 18�� û�ҳ� ��� 
				}
				else if(age >= 65){
					price = CHILDAFTERTOTALPRICE;	// �� 65�� �̻� = ��� ��� 
				}
				else{
					price = ADULTAFTERTOTALPRICE;	// ������ � ��� 
				}
		}
		
		// �ֹ� ����
		if(orderCount <= 10){
			price = price * orderCount;
		}
		
		// ������
		switch(discount){
			case 1 :					// ������ ���� 
				price = price;
				break;
			
			case 2 :					// ����� 50% ���, ����/��ũ  (+����1��) 
				price = price * 0.5;
				break;
			
			case 3 :					// ���������� 50% ���, ����/��ũ  (+����1��)
				price = price * 0.5;
				break;
				
			case 4 :					// �ް��庴 49% ���, ����  (+����1��)
				price = price;
				if((ticketSelect == 3) || (ticketSelect == 4)){
					price = price * 0.51;
					}
				break;
			
			case 5 :					// �ӻ�� 50% ���, ����
				price = price;
				if((ticketSelect == 3) || (ticketSelect == 4)){
					price = price * 0.5;
					}
				break;
				
			case 6 :					// �ٵ��� 30% ���, ����
				price = price;
				if((ticketSelect == 3) || (ticketSelect == 4)){
					price = price * 0.5;
					}
				break;		
			}
		
		printf("\n������ %d���Դϴ�. �����մϴ�.\n", price);
		
		int again;
		
		printf("\n��� �߱� �Ͻðڽ��ϱ�? \n1. Ƽ�� �߱�\n2. ����\n");
		scanf("%d", &again);
		if(again == 2 ){
			break; 
		}
	
	}
	return 0;
}
