#include<stdio.h>
#include <time.h>

int main()
{
	for(;;){
		
		int ticketSelect[10] = {0}, idNumber, backIdNumber, orderCount[10] = {0}, discount[10] = {0};	
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
		
		//ȭ�� ��� 
		printf("\n[���� ��¥ : %d] \n\n", todayYMD);
		
		// ���� ���� 
		do{  
			printf("������ �����ϼ���. \n1. 1DAY \n2. After4(���� 4�ú��� ����)\n3. 1DAY(�����̿��) \n4. After4(�����̿��, ���� 4�ú��� ����)\n");
			scanf("%d", &ticketSelect[index]);
			if(!(ticketSelect[index] ==1 || ticketSelect[index] ==2 || ticketSelect[index] ==3 || ticketSelect[index] ==4 )){
				printf("\n�߸��Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.\n\n");
				}
		}while (!(ticketSelect[index] ==1 || ticketSelect[index] ==2 || ticketSelect[index] ==3 || ticketSelect[index] ==4 ));
	
	
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
			if(orderCount[index] > 10){
				printf("\n�߸��Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.\n\n");
				}
		}while(orderCount[index] > 10);
			
		// ������ �Է� 
		do{
			printf("\n�������� �����ϼ���. \n1. ����(���� ���� �ڵ�ó��)\n2. ����� \n3. ���������� \n4. �ް��庴 \n5. �ӻ��\n6. �ٵ���\n");
			scanf("%d", &discount);
			if(!(discount[index] ==1 || discount[index] ==2 || discount[index] ==3 || discount[index] ==4 || discount[index] == 5 || discount[index] == 6)){
				printf("\n�߸��Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.\n\n");
				}
		}while (!(discount[index] ==1 || discount[index] ==2 || discount[index] ==3 || discount[index] ==4 || discount[index] == 5 || discount[index] == 6));
		
		// ������ ��� 
		int age = (todayYMD - (idNumber))/10000;
		
		if((backIdNumber == 1) || (backIdNumber == 2)){
			age = age + 100;
		} 
		
		// ���̺� ���� ����
		int price = 0;
	
		switch(ticketSelect[index]){
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
		if(orderCount[index] <= 10){
			price = price * orderCount[index];
		}
		
		// ������
		switch(discount[index]){
			case 1 :										// ������ ���� 
				price = price;
				break;
			
			case 2 :										// ����� 50% ���, ����/��ũ  (+����1��) 
				price = price * 0.5;
				break;
			
			case 3 :										// ���������� 50% ���, ����/��ũ  (+����1��)
				price = price * 0.5;
				break;
				
			case 4 :										// �ް��庴 49% ���, ����  (+����1��)
				price = price;
				if((ticketSelect[index] == 3) || (ticketSelect[index] == 4)){
					price = price * 0.51;
					}
				break;
			
			case 5 :										// �ӻ�� 50% ���, ����
				price = price;
				if((ticketSelect[index] == 3) || (ticketSelect[index] == 4)){
					price = price * 0.5;
					}
				break;
				
			case 6 :										// �ٵ��� 30% ���, ����
				price = price;
				if((ticketSelect[index] == 3) || (ticketSelect[index] == 4)){
					price = price * 0.5;
					}
				break;		
			}
		
		printf("\n������ %d���Դϴ�. �����մϴ�.\n", price);
	
		int again;
		
		do{
			printf("\n��� �߱� �Ͻðڽ��ϱ�? \n1. Ƽ�� �߱�\n2. ����\n");
			scanf("%d", &again);
			if(!(again ==1 || again ==2)){
				printf("\n�߸��Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.\n\n");
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
					printf("1DAY(�����̿��)");}
				else if(ticketSelect[i] == 4){
					printf("After4(�����̿��)");}
				
				printf(" ");
				
				if(age < 1){
					printf("����");}
				else if((age >= 1) && (age < 3)){
					printf("���̺�");}
				else if((age >= 3) && (age < 13)){
					printf("���");}
				else if((age >= 13) && (age < 18)){
					printf("û�ҳ�");}
				else if(age >= 65){
					printf("����");}
				else{printf("�");}
			
				printf("\tX %d��", orderCount[index]);
				printf("\t%d��", price);
				printf("\t*������ : ");
				
				if(discount[i] == 1){
					printf("����������");
				}
				else if(discount[i] == 2){
					printf("����� 50% ����");
				} 
				else if(discount[i] == 3){
					printf("���������� 50% ����");
				}
				else if(discount[i] == 4){
					printf("�ް��庴 49% ����");
				}
				else if(discount[i] == 5){
					printf("�ӻ�� 50% ����");
				}
				else if(discount[i] == 6){
					printf("�ٵ��� 30% ����");
				}
				
			printf("\n"); 
				 
			}
			int totalPrice;
			for(int k = 0; k < index; k++){
				totalPrice += price;
			}
			printf("����� �Ѿ��� %d�Դϴ�.", totalPrice);
			
			break;
		}
	
}
	return 0;
}
