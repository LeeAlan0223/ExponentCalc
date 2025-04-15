/*標頭檔*/ 
#include<stdio.h>
#include<stdlib.h>

void text_interface(float* number ,int* power);//用指標要改變記憶體的值才要用"*"連結(文字介面) 
void result(float numbe,int power,float sum);//將變數帶入函式(文字介面)
void Finish(void);//結束 
float Exponentiation_increase_and_decrease(float sum,int power);//單純計算不需要用到"*"


 /*已除完錯*/
int main(void){
	
	int power; //宣告變數 
	float number,sum; 

	text_interface(&number,&power); //取代原本的文字介面，並加入指標 "&" 
					
	if(number == -1){
		return 1;//將錯誤值回傳 
		/*
		查資料找到
		return 1 和 return 0 的差別
		return 1:程式執行有錯，回報給電腦並結束執行程式
		return 0:程式執行能正常運行，回報給電腦並結束執行程式 
		*/  
	}
	 
	result(number,power,sum);//函式呼叫(模組化) 
	
	Finish();//呼叫結束函式 
	return 0; //將值回傳 	
}

void text_interface(float* number ,int* power){
	
	printf("輸入底數(可為任意數字): "); //文字介面 
	scanf("%f", number); //輸入變數 
	printf("輸入次方數(數字只能為正負): "); //文字介面 
	scanf("%d", power); //輸入變數
	if(*number == 0 && *power < 0) { //因為執行0^-1次方會錯誤運算 
		printf("\n");
		printf("無法執行0的負次方運算\n");	//文字介面 
		*number = -1 ;//將值設為-1來觸發主程式的 return 1;只能在主程式出現 
		
		Finish();
		return;
	//system("pause");
	/*
	system("pause"); 
	只通用在 win系統
	打完的程式exe檔
	單獨執行輸入完他會直接結束
	因為 "Dev C++" 內建有暫停功能等使用者確認執行結果才會結束 
	*/ 
	} 	
}

void result(float number,int power,float sum){
	sum = Exponentiation_increase_and_decrease(number, power);
	printf("%2.10f ^ %d = %3.10f\n",number,power,sum); //將結果列印出來 "文字介面"
}

void Finish(void){
	printf("請輸入Enter鍵結束");
	while(getchar()!='\n');	//相當於阻擋牆用while持續偵測是否有輸入"\n"(也就是Enter) 也是為了清除殘留的 "\n"(Enter) 
	getchar();	//偵測是否有按鍵輸入但必須是Enter,因為上方的while
	
	//system("pause");  通用在WIN系統不能跨平台 
	/*  
	//相當於 system("pause");的功效 
	printf("請輸入Enter鍵結束");
	getchar();	為了緩衝前面scanf殘留的的'\n'(Enter) 
	getchar();	這才是真正使用者輸入的鍵 
	*/ 
	
}

float Exponentiation_increase_and_decrease(float number,int power){
	float sum = 1.0; //儲存值為 1 開始因為底下的"sum*=number"初始值為0的話任何數乘進去都是0
	if(power==0){
		sum = 0; //將函數等於0的結果考慮進去 
	}
	
	else if(power > 0){
		for(int i = 0;i < power; i++){
			sum*=number; 
			/*
			將sum*=number做連續相乘如: 
			3^1 sum= 3*1= 3 (乘1是因為初始值是1) 
			3^2		 3*3= 9  
			3^3		 9*3= 27
			3^4		 27*3=81
			*/ 
		}
	 }else{ // if(power < 0)
	 	for(int i = 0;i < -power; i++){
			sum/=number;  //底下 sum= 1.0 / sum;用了就要將此行的sum/=numder改成 sum*=numder
			/*
			將sum*=number做連續相乘如: 
			3^-1 sum= 	 3/1      = 0.3333 (除1是因為初始值是1) 
			3^-2		 0.3333/3 = 0.1111  
			3^-3		 0.1111/3 = 0.0370
			3^-4		 0.0370/3 = 0.0123
			*/ 
	 		}
	 		//sum= 1.0 / sum; 這可用可不用因為我將"sum/=number"改成除 (此行就是將值成完再倒數)
	 
		}
		
		return sum;
} 
