#include<stdio.h>
#include <time.h>

int main()
{
	int ticketSelect, idNumber, backIdNumber, orderCount, discount, age, price, countPrice, discountPrice, totalPrice, again;	
	int ticketSelectArr[10]={0}, orderCountArr[10]={0}, discountArr[10]={0}, discountPriceArr[10] = {0};
	int index = 0;
		 
	// ��ũ�����
	const int ADULT_DAY = 56000, TEEN_DAY = 50000, CHILD_DAY = 46000, BABY_DAY = 15000, FREE = 0;
	const int ADULT_AFTER = 45000, TEEN_AFTER = 40000, CHILD_AFTER = 35000, BABY_AFTER = 15000;
		
	// ��������� 
	const int ADULT_DAY_TOTAL = 59000, TEEN_DAY_TOTAL = 52000, CHILD_DAY_TOTAL = 47000, BABY_DAY_TOTAL = 15000;
	const int ADULT_AFTER_TOTAL = 48000, TEEN_AFTER_TOTAL = 42000, CHILD_AFTER_TOTAL = 36000, BABY_AFTER_TOTAL = 15000;
		
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
		
	do{
		ticketSelect = 0, idNumber = 0, backIdNumber = 0, orderCount = 0, discount = 0, age = 0,
		price = 0, countPrice = 0, discountPrice = 0; // �����ʱ�ȭ 
	
		//ȭ�� ��� 
		printf("************* COCOLAND ************* \n\t[���� ��¥ : %d] \n\n", todayYMD);
		
		// ���� ���� 
		do{  
			printf(" ������ �����ϼ���.(After4�� ���� 4�ú��� ����) \n 1. ��ũ�̿�� [1DAY]\n 2. ��ũ�̿�� [After4]\n 3. �����̿�� [1DAY]\n 4. �����̿�� [After4]\n");
			scanf("%d", &ticketSelect);
			
			if(!(ticketSelect ==1 || ticketSelect ==2 || ticketSelect ==3 || ticketSelect ==4 )){
				printf("\n �߸��Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.\n\n");
				}
				
		}while (!(ticketSelect ==1 || ticketSelect ==2 || ticketSelect ==3 || ticketSelect ==4 ));
	
		// �ֹι�ȣ �Է� 
		do{ 
			printf("\n �ֹι�ȣ �� 6���ڸ� �Է��ϼ���\n");
			scanf("%d", &idNumber);
			
			if(!((idNumber >= 000101) && (idNumber <= 991231))){
				printf("\n �߸��Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.\n\n");
				}
				
		}while (!((idNumber >= 000101) && (idNumber <= 991231)));
		
		do{ 
			printf("\n �ֹι�ȣ �� 1���ڸ� �Է��ϼ���\n");
			scanf("%d", &backIdNumber);
			if(!(backIdNumber ==1 || backIdNumber ==2 || backIdNumber ==3 || backIdNumber ==4 )){
				printf("\n �߸��Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.\n\n");
				}
				
		}while(!(backIdNumber ==1 || backIdNumber ==2 || backIdNumber ==3 || backIdNumber ==4 ));
		
		// ���� �Է� 
		do{
			printf("\n ��� �ֹ��Ͻðڽ��ϱ�? (�ִ� 10��) \n");
			scanf("%d", &orderCount);
			if(orderCount > 10){
					printf("\n �߸��Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.\n\n");
				}
				
		}while(orderCount > 10);
			
		// ������ �Է� 
		do{
			printf("\n �������� �����ϼ���. \n 1. ����(���� ���� �ڵ�ó��)\n 2. ����� \n 3. ���������� \n 4. �ް��庴 \n 5. �ӻ��\n 6. �ٵ���\n");
			scanf("%d", &discount);
			if(!(discount ==1 || discount ==2 || discount ==3 || discount ==4 || discount == 5 || discount == 6)){
				printf("\n �߸��Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.\n\n");
			}
			
		}while (!(discount ==1 || discount ==2 || discount ==3 || discount ==4 || discount == 5 || discount == 6));
		
		// ������ ��� 
		age = (todayYMD - (idNumber))/10000;
		
		if((backIdNumber == 1) || (backIdNumber == 2)){
			age = age + 100;
		} 
		
		// ���̺� ���� ����
		switch(ticketSelect){
			case 1 : 
				if(age < 1){
				price = FREE;								// 0 ~ 12���� = ���� 
				} 
				else if((age >= 1) && (age < 3)){
					price = BABY_DAY;						// 12���� �̻� 36���� �̸� = ���̺� ���  
				}
				else if((age >= 3) && (age < 13)){
					price = CHILD_DAY;						// 36���� �̻� ~ �� 12��  =��� ��� 
				}
				else if((age >= 13) && (age < 18)){
					price = TEEN_DAY;						// �� 13�� ~ 18�� = û�ҳ� ��� 
				}
				else if(age >= 65){
					price = CHILD_DAY;						// �� 65�� �̻� = ��� ��� 
				}
				else{
					price = ADULT_DAY;						// ������ = � ��� 
				} 
				break;
				
			case 2 :
				if(age < 1){
				price = FREE;								// 0 ~ 12���� = ���� 
				} 
				else if((age >= 1) && (age < 3)){
					price = BABY_AFTER;						// 12���� �̻� 36���� �̸� = ���̺� ���  
				}
				else if((age >= 3) && (age < 13)){
					price = CHILD_AFTER;					// 36���� �̻� ~ �� 12�� = ��� ��� 
				}
				else if((age >= 13) && (age < 18)){
					price = TEEN_AFTER;						// �� 13�� ~ 18�� = û�ҳ� ��� 
				}
				else if(age >= 65){
					price = CHILD_AFTER;					// �� 65�� �̻� = ��� ��� 
				}
				else{
					price = ADULT_AFTER;					// ������ = � ��� 
				}
				break;
				
			case 3 :
				if(age < 1){
				price = FREE;								// 0 ~ 12���� = ���� 
				} 
				else if((age >= 1) && (age < 3)){
					price = BABY_DAY_TOTAL;					// 12���� �̻� 36���� �̸� = ���̺� ���  
				}
				else if((age >= 3) && (age < 13)){
					price = CHILD_DAY_TOTAL;				// 36���� �̻� ~ �� 12�� = ��� ��� 
				}
				else if((age >= 13) && (age < 18)){
					price = TEEN_DAY_TOTAL;					// �� 13�� ~ 18�� = û�ҳ� ��� 
				}
				else if(age >= 65){
					price = CHILD_DAY_TOTAL;				// �� 65�� �̻� = ��� ��� 
				}
				else{
					price = ADULT_DAY_TOTAL;				// ������ = � ��� 
				} 
				break;
				
			case 4 :
				if(age < 1){
				price = FREE;								// 0 ~ 12���� = ���� 
				} 
				else if((age >= 1) && (age < 3)){
					price = BABY_AFTER_TOTAL;				// 12���� �̻� 36���� �̸� = ���̺� ���  
				}
				else if((age >= 3) && (age < 13)){
					price = CHILD_AFTER_TOTAL;				// 36���� �̻� ~ �� 12�� = ��� ��� 
				}
				else if((age >= 13) && (age < 18)){
					price = TEEN_AFTER_TOTAL;				// �� 13�� ~ 18�� = û�ҳ� ��� 
				}
				else if(age >= 65){
					price = CHILD_AFTER_TOTAL;				// �� 65�� �̻� = ��� ��� 
				}
				else{
					price = ADULT_AFTER_TOTAL;				// ������ = � ��� 
				}
				break;
		}
		
		
		// �ֹ� ����
		if(orderCount <= 10){
			countPrice = price * orderCount;
		}
		
		// ������
		switch(discount){
			case 1 :										// ������ ���� 
				discountPrice = countPrice;
				break;
			
			case 2 :										// ����� 50% ���, ����/��ũ  (+����1��) 
				discountPrice = countPrice * 0.5;
				break;
			
			case 3 :										// ���������� 50% ���, ����/��ũ  (+����1��)
				discountPrice = countPrice * 0.5;
				break;
				
			case 4 :										// �ް��庴 49% ���, ����  (+����1��)
				discountPrice = countPrice;
				if((ticketSelect == 3) || (ticketSelect == 4)){
					discountPrice = countPrice * 0.51;
					}
				break;
			
			case 5 :										// �ӻ�� 50% ���, ����
				discountPrice = countPrice;
				if((ticketSelect == 3) || (ticketSelect == 4)){
					discountPrice = countPrice * 0.5;
					}
				break;
				
			case 6 :										// �ٵ��� 30% ���, ����
				discountPrice = countPrice;
				if((ticketSelect == 3) || (ticketSelect == 4)){
					discountPrice = countPrice * 0.5;
					}
				break;		
			}
		
		printf("\n ������ %d���Դϴ�. �����մϴ�.\n", discountPrice);
		
		ticketSelectArr[index] = ticketSelect;
		orderCountArr[index] = orderCount;
		discountArr[index] = discount;
		discountPriceArr[index] = discountPrice;
		totalPrice += discountPrice;
		
		index++;
		
		printf("\n ��� �߱� �Ͻðڽ��ϱ�? \n1. Ƽ�� �߱�\n2. ����\n");
		scanf("%d", &again);
		
	} while(again == 1);
	
	printf("\n COCOLAND�� �̿����ּż� �����մϴ�.\n");
		
	// ������ ���
	printf("\n\n************* COCOLAND *************\n");
	printf("   %s\t\t\t%s\t\t%s\n", "���û���", "����", "������");
			
	for (int i = 0; i < index; i++) {
		switch (ticketSelectArr[i]) {
			case 1:
				printf("%s %5s","��ũ�̿��","1Day");
				break;
			case 2:
				printf("%s %5s","��ũ�̿��","After4");
				break;
			case 3:						
				printf("%s %5s","�����̿��","1Day");
				break;
			case 4:
				printf("%s %5s","�����̿��","After4");
				break;
			default:
				break;
			}
				
		printf(" x %d ��\t\t%d��\t\t",orderCountArr[i], discountPriceArr[i]) ;
				
		switch (discountArr[i]) {
			case 1:
				printf("%s\n","����");
				break;
			case 2:
				printf("%s\n","����� ���");
				break;
			case 3:
				printf("%s\n","���������� ���");
				break;
			case 4:
				printf("%s\n","�ް��庴 ���");
				break;
			case 5:
				printf("%s\n","�ӻ�� ���");
				break;
			case 6:
				printf("%s\n","�ٵ��� �ູī�� ���");
				break;
			default:
				break;
				}
			}
		
	printf("\n����� �Ѿ��� %d�� �Դϴ�.", totalPrice);
	printf("\n=====================================================================================\n") ;
	
	return 0;
}
