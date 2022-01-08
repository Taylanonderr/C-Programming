#include<stdio.h>
#include<string.h>
#include<math.h>
double pow_fonk(char pol[1000],int i,double arr[100],int k);
void print_fonk(double sonuc[100],double arr[100],int k);			//hocam ilk değerler doğru basıyor sonraki değerler yanlış neden çok baksamda farkedemedim bir türlü basit bir hata muhtemelen
int main(){
FILE *dosya1;
FILE *dosya2;
FILE *dosya3;
int i,x,m,w,d,p,k;
int c=0,t=0,s=0,n=0,flag=1,j=0,sayac=0,sayma=0;
char pol[1000],b[100],number[100],ikili[100][10],v[100];
double arr[100],a,sayi[100],katsayi[100],sayi1,toplam,temp,sonuc[100],kat_x,result[100];
pol[0]=0;
dosya1=fopen("values.txt","r");
dosya2=fopen("polynomial.txt","r");
	for(k=0;fscanf(dosya1,"%lf",&a)!=EOF;k++){
		arr[k]=a;
	}
	for(x=0;fscanf(dosya2,"%s",b)!=EOF;x++){		/*dosyanın sonuna kadar dosya içindeki bilgiyi kullanabilmek için char arrete attigim dongu*/
		strcat(pol,b);			/*burda toplama ve çıkarma işlemlerinde kullanılabilecek boşluk için önlem aldım*/
		printf("%s\n",pol);
	}
	while(sayma<k){		/*inputtaki sayilar için teker teker hesap dongusu*/
	p=0;
	j=0;
	n=0;
	w=0;
	m=0;
	c=0;
	t=0;
	sayac=0;
	toplam=0;
	sayi1=0;
		for(i=0;i<strlen(pol);i++){		/*polinomdaki karaker sayısı kadar dongu kurup islem ve hesaplamaları bu dongu icinde yaptim*/
		if(pol[i]!='+' && pol[i]!='-' && pol[i]!='^' ){		/*burda sayi ve x kavramlari icin yaptirdigim islemler icin kosul koydum*/
			if(pol[i]=='x' && pol[i+1]=='^' ){			/*eger xin katasıyısı yoksa bu islemleri yaptirdim*/
				if(pol[i-1]=='+' || pol[i-1]=='-'){
					toplam=pow_fonk(pol,i,arr,sayma);
					sscanf(number,"%lf",&sayi1);
				   sonuc[sayac]=toplam;
				   sayac++;
				}
				else
				{
				toplam=pow_fonk(pol,i,arr,sayma);
				if(pol[i-1]!='+' && pol[i-1]!='-'){		/*eger xin katsayisi varsa bu islemleri yaptirdim*/
				   sscanf(number,"%lf",&sayi1);
				   sonuc[sayac]=toplam*sayi1;
					  
					   sayac++;
				}
				if(pol[i-1]=='+' || pol[i-1]=='-')		/**/
				{
					toplam=pow_fonk(pol,i,arr,k);
					sonuc[sayac]=toplam;
					sayac++;
				}
				}
			}			
			
		if(pol[i]!='x' && pol[i-1]!='+' && pol[i-1]!='-'){		/*xten önceki uzun katsayilarin okunmasinda ve üssüz ifadelerde kullandigim kosul*/
			for(w=0;pol[i+w]!='+';w++){				/*+ ev -'ye kadar arattim*/
				if(pol[i+w]=='-'){
					break;
				}
				if(pol[i+w]=='^'){			/*eger üslü ifade varsa islemlerden cikarttim*/
					p=1;
				}

			}
			if(p!=1){				/*üslü ifade ile karsilasmama durumunda yapilacak islem sirasi*/
				for(w=0;pol[i+w]!='x';w++){
					number[c]=pol[i+w];		/*polinom icindeki sayilari topladigim kisim*/
					sscanf(number,"%lf",&sayi1);		/*chari double a cevirdigim kisim*/
					kat_x=arr[sayma]*sayi1;		/**/
				}
				sonuc[sayac]=kat_x;		/*katsayi toplamini kaydettim*/
				sayac++;			/*islem sayisini arttirdim*/

			}
			
		}	

	}
		if(pol[i]=='+' || pol[i]=='-'){		/*+ ve - islemi ile karsilastigimdaki durum*/
			if(pol[i]!='^'){
				for(w=1;pol[i+w]!='x';w++){
					number[c]=pol[i+w];

					c++;
				}
				number[c]=' ';
				sscanf(number,"%lf",&sayi1);


				katsayi[j]=sayi1*arr[sayma];

				j++;
				n++;
				c=0;
				t=0;
			}
		}		
		}
		printf("%lf    \n",sonuc[0]);
			for(i=0;pol[i]!='\0';i++){

		if(pol[i]=='+'){
			sonuc[m+1]=sonuc[m]+sonuc[m+1];		/*burda + ve - işlemleri için önceden hesapladığım parça işlemlerin toplamasını yaptım*/
			sonuc[m]=0;
			m++;
		}
		if(pol[i]=='-'){						/*burda + ve - işlemleri için önceden hesapladığım parça işlemlerin çıkarmasını yaptım*/
			sonuc[m+1]=sonuc[m]-sonuc[m+1];
			sonuc[m]=0;
			m++;
		}			
	}
	printf("%lfsonuc,%d\n",sonuc[m],m);		
		result[sayma]=sonuc[m];
		sonuc[m]=0;
		sayma++;
		m=0;

	}
print_fonk(result,arr,k);
fclose(dosya1);
fclose(dosya2);
}


double pow_fonk(char pol[],int i,double arr[],int k){		/*sayilarin üssünü aldigim fonksiyon*/
	double toplam,flag=1,sayi1;
	char v[100];
	int x;
		x=0;
	while(flag!=0){			/*sayinin üs indexini okudugum dongu*/
		if(pol[i+2+x]!='+' && pol[i+2+x]!='-' && pol[i+2+x]!='\0'){
			v[x]=pol[i+2+x];
			x++;
		}
		else{
			flag=0;
		}
		if(pol[i+2+x]=='\0'){
			break;					
		}		
	}
	flag=1;		/*donguden cikma kosulum*/
	v[x]='\0';
	sscanf(v,"%lf",&sayi1);		/*okudugum char tipi sayılari doublea cevirdim*/
	toplam=pow(arr[k],sayi1);	/*buldugum indexe gore sayinin ussunu hesapladim*/
	return(toplam);
		
}

void print_fonk(double sonuc[],double arr[],int k){		/*dosyaya yazdirdigim fonksiyon*/
	FILE *dosya3;
	int a=0;
	dosya3=fopen("evaluations.txt","w");		/*bu isimde yazma amaçlı dosya okudum*/
			/*inputtaki sayi adeti kadar hesaplamalari dosyaya yazdirdim*/
	for(a=0;a<k;a++){	
		fprintf(dosya3,"%.2lf\n",sonuc[a]);
	}
	
	fclose(dosya3);
}

