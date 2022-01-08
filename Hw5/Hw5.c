#include <stdio.h>
#include <string.h>

int repeat(char a[5000][3],int size,int size1[728]);
int y_fonk(char file_name[20], int size1[728]);
double disimilitary(int size1[728], int sayac1, int size2[728], int sayac2);

int main(){
	int r,l,t,n[768];
	int i;
	int size1[728], size2[728], size3[728], size4[728], size5[728], size6[728];
	int sayac1, sayac2, sayac3, sayac4, sayac5, sayac6;
	double toplam1,toplam2,toplam3,toplam4,toplam5;
	sayac1=y_fonk("language_1.txt", size1);		/*2li dongu sayisini language1 icin hesapladim*/
	sayac2=y_fonk("language_2.txt", size2);		/*2li dongu sayisini language2 icin hesapladim*/
	sayac3=y_fonk("language_3.txt", size3);		/*2li dongu sayisini language3 icin hesapladim*/
	sayac4=y_fonk("language_4.txt", size4);		/*2li dongu sayisini language4 icin hesapladim*/
	sayac5=y_fonk("language_5.txt", size5);		/*2li dongu sayisini language5 icin hesapladim*/
	sayac6=y_fonk("language_x.txt", size6);		/*2li dongu sayisini language6 icin hesapladim*/
	toplam1=disimilitary(size1,sayac1,size6,sayac6);	/*dissimiliritary hesaibini 1.ve x dosyasi icin yapip ekrana bastiriyorum*/
	toplam2=disimilitary(size2,sayac2,size6,sayac6);	/*dissimiliritary hesaibini 1.ve x dosyasi icin  yapip ekrana bastiriyorum*/
	toplam3=disimilitary(size3,sayac3,size6,sayac6);	/*dissimiliritary hesaibini 1.ve x dosyasi icin  yapip ekrana bastiriyorum*/
	toplam4=disimilitary(size4,sayac4,size6,sayac6);	/*dissimiliritary hesaibini 1.ve x dosyasi icin  yapip ekrana bastiriyorum*/
	toplam5=disimilitary(size5,sayac5,size6,sayac6);	/*dissimiliritary hesaibini 1.ve x dosyasi icin  yapip ekrana bastiriyorum*/

}
int y_fonk(char file_name[20], int size1[728]){		/*okudugum ikilileri arraye aldigim fonksiyon*/
	FILE * dosya1;
	char a[1200][3],b[1],arr[2000][2],c[1],n[728],file2[1],file3[1],file4[1],file5[1];
	int x=1,t,y,sayac=0,m,flag=1,i,s;
	dosya1=fopen(file_name,"r");
	b[0]=fgetc(dosya1);		/*ikili arraydeki ilk elemani tuttugum karakter*/
	b[1]='\0';
	a[0][0]=b[0];			/*ikili arraye bu karakteri attim*/
	while(c[0]!=EOF){		/*dosya sonuna gelene kadar okuma yapma kosulu olan dongu*/
		t=0;
		c[0]=fgetc(dosya1);	/*dosyadan karakter okuduğum kisim*/
		if(c[0]==EOF){		/*dosya sonuna gelince döngüyü sonlandirma kosulu*/
			break;
			}
		c[1]='\0';			/*karakterin sonuna null karakterini attim*/
		if(c[0]=='\n'){		/*new line karakterine gelince newlinelı ikili olusturmama kosulum*/
			c[0]=fgetc(dosya1);		/*bir sonraki karakteri okuyorum*/
				if(c[0]==EOF){		/*dosya sonuna gelseydi döngu sonlandirma kosulum*/
					break;
				}
			a[sayac-1][1]=c[0];		/*newline karakter geldiginde yeni aldigim karakteri arrayin 2. indisine attigim yer*/
			a[sayac][0]=c[0];		/*bir sonraki ikilide ilk indise tekrardan okudugum karakteri attim*/
				t=1;
		}
		if((sayac)==0){				/*arrayin ilk okumasindaki 1.indisin atanmasi*/
			a[0][1]=c[0];
		}
		if((sayac)!=0 && t==0 && c[0]!=EOF){		/*okudugum karakteri arrayin 1.indisine attigim kisim*/
			a[sayac][1]=c[0];		
			a[sayac][2]='\0';	
		}
		if((sayac)!=0 && c[0]!=EOF && t==0){		/*okudugum karakterleri belli sartlara göre ilk indise kaydettigim kisim*/
			if(a[sayac][0]==' ' && c[0]=='\n'){		/*bosluk ve newline gelirse donguye kaydettirmedigim kosul*/
				flag=0;
			}	
			if(a[sayac][0]=='\n'&& c[0]=='\n' ){	/*2 newline gelmesi kosulunda donguye kaydettirmedigim kosul*/
				flag=0;
			}
			if(a[sayac][0]=='\n'&& c[0]==' ' ){		/*new line ve bos karakter gelme durumuda donguye kaydetmedigi kosul*/
				flag=0;
			}
			if(a[sayac][0]==' '  && c[0]==' '){		/*iki bosluk karakter olması durumunda arraye bu ikiliyi kaydetmedigim kosul*/
				flag=0;
			}
			if(flag==1){							/*olmaması gereken kosullar haricinde dongunun ilk indisine atama yaptigim kosul*/
				a[sayac+1][0]=c[0];
				sayac++;							/*dongude ikili indis sayisini saydigim sayac*/
				}
			
			flag=1;
		}
		else if((sayac)==0 && t==0){	/*arrayde ilk eleman icin yazdigim kosul */
			a[sayac+1][0]=c[0];
			sayac++;
		}
		else if(t==1){	/*newline icin tuttugum bos kosul ise yaramiyor*/
		}
			
		else	
			break;	
	}
	a[sayac-1][0]='\0';	/*tuttugum arrayin son elemana null elemanini atadim*/
	sayac=sayac-1;	
	repeat(a,sayac,size1);		/*karsilatirma yaptigim fonksiyon*/
	fclose(dosya1);	
	return sayac;		/*2li sayisini donduruyorum*/
}

int repeat(char a[10000][3],int size,int size1[728]){	/*bu fonksiyonda dosya içerisindeki ikililerin sayılarını bir arrayde tutma işini yaptım*/
	int i;
	char array[728][3];
	int count=0,r,l,t;
	t=0;
	for(r=0;r<27;r++){		/*a dan z ye boşlukta dahil olabilicek tüm ikilileri arraye alıp dosyadaki ikililer ile karşılaştırdığım döngü*/
		for(l=0;l<26;l++){
			array[t+l][0]=97+r;
			array[t+l][1]=97+l;
			array[t+l][2]='\0';
		}
		t=t+l;
		if(r==26){		/*bosluklu 2lileri olusturma kosulum*/
			t=t-l;
			for(l=0;l<26;l++){
				array[t+l][0]=' ';
				array[t+l][1]='a'+l;
				array[t+l][2]='\0';		
			}
			t=t+l;
			for(l=0;l<26;l++){
				array[t+l][0]='a'+l;
				array[t+l][1]=' ';
				array[t+l][2]='\0';	
			}
		}
	}
	array[t][0]='\0';		/*arrayde eksik olan bir ' a'ifadesi vardı arraye bu ifadeyi attım*/
	array[702][0]='a';
	array[702][1]=' ';
	array[702][2]='\0';
	for(i=0;i<728;i++){		/*array icindeki elemanlar ile tüm 2li ifadeleri karşılatirip her ikilide tekrar eden ifade sayisini size arrayinde tuttum*/
		for(t=0;t<size;t++){
			if(strcmp(array[i],a[t])==0){
				count++;
			}
		}
		size1[i]=count;		/*ikililerin tekrarlanma sayisini tuttugum donguye atama yaptigim kisim*/
		count=0;
	}
	array[702][0]='a';
	array[702][1]=' ';
	array[702][2]='\0';

}

double disimilitary(int size1[728], int sayac1, int size2[728], int sayac2){		/*frekans ile dissimiliritary hesapladigim fonksiyon*/
	int i;
	double dissi,toplam=0;
	for(i=0;i<728;i++){		/*frekans ile dissimiliritary hesabini yaptigim dongu*/
		dissi=(size1[i]*1.0/sayac1)-(size2[i]*1.0/sayac2);
		if(dissi<0){
			dissi*=-1;
		}
		toplam=toplam+dissi;
	}
	printf("%lf\n",toplam);	/*mainde 5 kez print etmemek icin bu fonksiyonda dissimilitary degerini bastirttim*/
	return(toplam);	/*maine döndürdügüm son dissimiliritary degeri */
}



