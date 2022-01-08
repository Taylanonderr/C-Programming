#include <stdio.h>
#include <string.h>

int main(){
	int i=0,a=1,b,x=0,t,tanim_size,n,p,m,ar,ph;
	int xkoor[1][2],pkoor[1][2],mkoor[1][2],akoor[1][2],phkoor[1][2];
	char kelime[150];
	char array[100],xa[250],pa[250],my[250],ary[250],phh[250];
	char arrayword[100][250];
	char tanimli[100][250]={"Xanthos","Patara","Myra","Arycanda","Phaselis"};
	FILE *dosya;
	dosya=fopen("input.txt","r");					/*dosya okuma işlemini yapmak için dosyayı açtım*/
	while(fscanf(dosya,"%s\n",kelime)!=EOF){			/*dosya sonuna kadar dönen bir döngü ile dosyadaki verileri atama islemi yaptim*/
		b=strlen(kelime);								/*her okuduğum stringin uzunluğunu hesapladim*/
		strcpy(arrayword[a-1],kelime);
		for(i=0;i<strlen(kelime);i++){				/*scaf ile okudugum kelimelerin sizeı kadar dongu yapip buyuk harfleri buldurdugum dongu kurdum*/
			if(kelime[i]>='A' && kelime[i]<='Z'){	/*büyük harf bulma sarti*/
				if(kelime[i]=='X'){					/*Xanthos kelimesini bulabilmek icin ilk harf kosulum*/	
					tanim_size=strlen(tanimli[0]);	/*X harfini yakaladiğimda bulmak istedigim kelimenin sizeını tuttum*/
					for(t=0;t<tanim_size;t++){		/*yukarda belirttigim size ile Xten sonraki harfleri bir arreyde tuttum*/
						array[t]=kelime[i+t];
					}
					array[t]='\0';
					if(strcmp(tanimli[0],array)==0){		/*tuttugum arraydeki kelime ile aradıgim kelimeyi karsılastirdigim kosul*/
						x=0;								/*horizontal yazdirmak için tuttugum degisken*/
						strcpy(xa,array);					/*print etmek iin kullanacagim kelime*/
						xkoor[0][0]=a;						/*print ederken kullanacagim y koordinatı*/
						xkoor[0][1]=i+1;					/*print ederken kullanacagim x koordinatı*/
					}
				}	
					
				if(kelime[i]=='P'){					/*X için yazdigim seyleri p harfi icinde yazdim-Patara icin*/
					tanim_size=strlen(tanimli[1]);
					for(t=0;t<tanim_size;t++){
						array[t]=kelime[i+t];
					}
					array[t]='\0';
					if(strcmp(tanimli[1],array)==0){
						p=0;
						strcpy(pa,array);
						pkoor[0][0]=a;
						pkoor[0][1]=i+1;
					}	
				}
				
				if(kelime[i]=='M'){				/*X icin yazdigim seyleri m harfi icinde yazdim*/
					
					tanim_size=strlen(tanimli[2]);
					for(t=0;t<tanim_size;t++){
						array[t]=kelime[i+t];
					}
					array[t]='\0';
					if(strcmp(tanimli[2],array)==0){
						m=0;
						strcpy(my,array);
						mkoor[0][0]=a;
						mkoor[0][1]=i+1;
					}	
				}
				
				if(kelime[i]=='A'){			/*X icin yazdigim seyleri A harfi icinde yazdim*/
					tanim_size=strlen(tanimli[3]);
					for(t=0;t<tanim_size;t++){
						array[t]=kelime[i+t];
					}
					array[t]='\0';
					if(strcmp(tanimli[3],array)==0){
						ar=0;
						strcpy(ary,array);
						akoor[0][0]=a;
						akoor[0][1]=i+1;
					}	
				}
				
				if(kelime[i]=='P'){			/*X icin yazdigim seyleri P harfi icinde yazdim-Phaselis icin*/
					tanim_size=strlen(tanimli[4]);
					for(t=0;t<tanim_size;t++){
						array[t]=kelime[i+t];
					}
					array[t]='\0';
					if(strcmp(tanimli[4],array)==0){
						ph=0;
						strcpy(phh,array);
						phkoor[0][0]=a;
						phkoor[0][1]=i+1;
					}	
				}
			}
		}
		a++;
	}
	b=0;
	/*yukarıda horizontal icin yazdiklarimi vertical icinde yazdim*/
	for(n=0;n<a;n++){		/*fscanf ile okudugum islem sayisi veya kelime sayisida denebilir dongu kurdum*/
		for(i=0;i<strlen(arrayword[n]);i++){		/*arrayde tuttugum kelimenin sizei kadar dongu kurdum*/
			if(arrayword[n][i]=='X'){				/*Büyük X harfini yakalama kosulum*/
				tanim_size=strlen(tanimli[0]);		/*bulmak istedigim kelimenin sizeini tuttum*/
				for(t=0;t<tanim_size;t++){			/*bulmak istedigim kelimenin sizei kadar döngü kurup vertical olarak karsılastirabilecegim kelimin harflerini atadigim dongü*/
					array[t]=arrayword[n+b][i];		/*harf harf atama yaparak vertical olan kelimeyi arraye atadim*/
					b++;
				}
				array[t]='\0';
				if(strcmp(tanimli[0],array)==0){	/*aradigim kelime ile okudugum kelimeyi karsilastirdim*/
					x=1;							/*print ederken vertical olma şartı (flagi) */
					strcpy(xa,array);				/*print ederken kullanacagim arraye kopyaladim*/
					xkoor[0][0]=n+1;				/*print ederken kullanacagim y koordinatini arraye atadim*/
					xkoor[0][1]=i+1;				/*print ederken kullanacagim x koordinatini arraye atadim*/
				}
			}	
			if(arrayword[n][i]=='P'){				/*X icin yaptiklarimin aynisini P icinde yaptim-Patara icin*/
				tanim_size=strlen(tanimli[1]);
				for(t=0;t<tanim_size;t++){
					array[t]=arrayword[n+b][i];
					b++;
				}
				array[t]='\0';
				if(strcmp(tanimli[1],array)==0){
					p=1;
					strcpy(pa,array);
					pkoor[0][0]=n+1;
					pkoor[0][1]=i+1;
				}
			}
			if(arrayword[n][i]=='M'){				/*X icin yaptiklarimin aynisini M harfi icinde yaptim*/
				tanim_size=strlen(tanimli[2]);
				for(t=0;t<tanim_size;t++){
					array[t]=arrayword[n+b][i];
					b++;
				}
				array[t]='\0';
				if(strcmp(tanimli[2],array)==0){
					m=1;
					strcpy(my,array);					
					mkoor[0][0]=n+1;
					mkoor[0][1]=i+1;
				}
			}
			if(arrayword[n][i]=='A'){			/*X icin yaptiklarimin aynisini A harfi icinde yaptim*/
				tanim_size=strlen(tanimli[3]);
				for(t=0;t<tanim_size;t++){
					array[t]=arrayword[n+b][i];
					b++;
				}
				array[t]='\0';
				if(strcmp(tanimli[3],array)==0){
					ar=1;
					strcpy(ary,array);	
					akoor[0][0]=n+1;
					akoor[0][1]=i+1;									

				}
			}
			if(arrayword[n][i]=='P'){		/*X icin yaptıklarimin aynisini P harfi icinde yaptim -Phaselis icin*/
				tanim_size=strlen(tanimli[4]);
				for(t=0;t<tanim_size;t++){
					array[t]=arrayword[n+b][i];
					b++;
				}
				array[t]='\0';
				if(strcmp(tanimli[4],array)==0){
					ph=1;
					strcpy(phh,array);
					phkoor[0][0]=n+1;
					phkoor[0][1]=i+1;				
				}
			}			
			b=0;	
		}
	}	
	/*vertical ve horizontal olan kelimeler icin bastirma kosullarim ve kelime ile x,y koordinatlarini yazdirdigim kosullar*/
	if(x==0){
		printf("%s (%d,%d) Horizontal\n",xa,xkoor[0][0],xkoor[0][1]);
	}
	else
		printf("%s (%d,%d) Vertical\n",xa,xkoor[0][0],xkoor[0][1]);
	if(p==0){
		printf("%s (%d,%d) Horizontal\n",pa,pkoor[0][0],pkoor[0][1]);
	}
	else
		printf("%s (%d,%d) Vertical\n",pa,pkoor[0][0],pkoor[0][1]);
	if(m==0){
		printf("%s (%d,%d) Horizontal\n",my,mkoor[0][0],mkoor[0][1]);
	}
	else
		printf("%s (%d,%d) Vertical\n",my,mkoor[0][0],mkoor[0][1]);
	if(ar==0){
		printf("%s (%d,%d) Horizontal\n",ary,akoor[0][0],akoor[0][1]);
	}
	else
		printf("%s (%d,%d) Vertical\n",ary,akoor[0][0],akoor[0][1]);
	if(ph==0){
		printf("%s (%d,%d) Horizontal\n",phh,phkoor[0][0],phkoor[0][1]);
	}
	else
		printf("%s (%d,%d) Vertical\n",phh,phkoor[0][0],phkoor[0][1]);
	
}


