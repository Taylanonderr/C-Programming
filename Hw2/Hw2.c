#include <stdio.h>
#include <stdlib.h>


void fonksiyon(double kume[][1000], int array[], int size,int sayi[]);
	


int main(){
  	int a=0,p,c,sayac,sayacx;
	int x=0,b=0,length,i=0,k=0;
	FILE *dosya; 
	double kume[1000][1000],toplam[1000];
	dosya=fopen("input.txt","r");					/*kullanacagim dosyayi okumak amaciyla actim */
	double f,temp,temp2,temp3;
	int array[1000],sayi[1000];
	int size = 0;

	while(fscanf(dosya,"%lf\n",&f)!=EOF){			/*dosya sonuna kadar okuyacağım bir döngü kurdum*/
		if(f==0.0){									/*okudugum sayi 0 oldugunda ve seperatöre denk geldiğgimde elde ettigim chunksların avarageını hesapladim*/
			a++;
			if(a==3){
				toplam[sayacx]=0;
				for(sayac=0;sayac<b;sayac++){		/*avarage hesabi*/
					toplam[sayacx]=(toplam[sayacx]+kume[x][sayac]);
				}
				toplam[sayacx]=toplam[sayacx]/(double)b;
				x++;
				sayacx++;
				array[size] = size;					/*chunk sizeını swap yaparken kullanmak icin arrayde tuttum*/
				size++;
				sayi[k]=b;							/*her chunktaki sayi adetini bir arraye atayip yazdirirken kullandim*/
				k++;
				b=0;
				
			}
		}
		if(a==3 && f!=0.0){							/*sadece seperatör girildiğinde 0 adet sayisini 0'ladim*/
			a=0;	
		}
		if(f!=0.0 && (a>=1) && (a<3)){				/*0 sayisi seperatör etmiyor ise chunk değerlerine normal 0 degerlerini atadim*/
			kume[x][b]=0.0;
			b++;
			a=0;
		}
		
		if(f!=0.0 || a>3) {							/*seperatör sayi adetini gecmis ve okudugum sayi artik 0 degilse sayiyi chunka atadim*/
			kume[x][b]=f;
			b++;
			if(f!=0.0 && a>3){						/*seperatör sayisindan fazla 0 var ve okudugum sayi 0 degilse 0 sayacini 0 ladim*/
				a=0;					
			}	
		}
		
	}
	sayi[k]=b;										/*döngüde son chunk degeri ile islem yapamadigim icin son chunk ile avarage hesabi ve size bilgilerini tutup hesapladim*/
	array[x] = size;
	toplam[sayacx]=0;
	for(sayac=0;sayac<b;sayac++){
		toplam[sayacx]=(toplam[sayacx]+kume[x][sayac]);
	}
	toplam[sayacx]=toplam[sayacx]/(double)b;
		
	fclose(dosya);									/*dosya okumasıni tamamladigim icin dosyayi kapattim*/

	for(p=0;p<=x;p++){								/*avarage hesabinı ve chunklarin sizeini swapleyerek yazdirirken kullanmayi amacladim*/
		c=0;
		for(c=0;c<=b;c++){
			if(toplam[p]<toplam[c]){				/*chunklari kücükten büyüge siralama kosulum*/
				temp=toplam[p];
				toplam[p]=toplam[c];
				toplam[c]=temp;
				
				temp2 = array[p];					/*ortalamaya göre sıraladığımız chunkların hangi sıra ile yerleşmesi gerektiğini belirten array.*/
				array[p] = array[c];
				array[c] = temp2;
				
				temp3 = sayi[p];					/*chunktaki eleman sayilarini yazdirma isleminde kullanabilmek icin swapledim*/
				sayi[p]=sayi[c];
				sayi[c]=temp3;
				
			}
		}
	}

	fonksiyon(kume,array,size,sayi);				/*dosyaya yazdirma fonksiyonunu calistirdim*/
	
}

void fonksiyon(double kume[][1000], int array[], int size, int sayi[]){			/*dosya yazma islemini yazdim*/
	int a;
	FILE *fp;
	int i,x,k=0;
	fp = fopen("output.txt","w");
	
	for(i = 0; i <=size; i++){		/*chunktaki elemanlari swaplayemeyecegim icin chunklarin avaragea göre kücükten büyüğe siralanmis sirasina göre dosyaya yazdirdim*/
		x = array[i];
		for(a=0;a<sayi[k];a++){		/*chunk elemanlarini teker teker yazdirdigim döngü*/
		fprintf(fp,"%lf  ",kume[x][a]); 
		}
		fprintf(fp,"\n");			/*her chunk degerinden sonra alt satira gectim*/
		k++;
	}
	
	
	fclose(fp);						/*dosya yazma islemi bittikten sonra dosyayi kapattim*/
	
}
