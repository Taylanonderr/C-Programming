#include<stdio.h>

int main(){
	int board_x=200;
	int board_y=300;
	int region_x=8;
	int region_y=8;
	int detector_x=20;
	int detector_y=20;
	
	int koordinatrx=20,koordinatry=20;	
	int attempts_remaining=10;
	int user_x,user_y,overlapx,tempx,tempy,x,y,overlapy;
	int a=1,b=0;
	int upgr_x1,upgr_y1,control;
	printf("Board = [%d x %d], marked region = [%d x %d], Detector = [%d x %d]\n",board_x,board_y,region_x,region_y,detector_x,detector_y);
	while(a==1){												//oyunun oynandığı loop
		printf("Enter the x coordinate of the move:	\n");
		scanf("%d",&user_x);		//kullanıcının girdiği x koordinatı
		printf("Enter the y coordinate of the move: \n");
		scanf("%d",&user_y);		//kullanıcının girdiği y koordinatı
	/*başta girilen değerleri farklı değişkenlere atayarak üzerlerinde değişiklik yapabilmek için değişken atamaları yaptım*/
		x=user_x;		
		y=user_y;
		tempx=koordinatrx;
		tempy=koordinatry;
		control=0;		//
		
		overlapx=0;
		for(;(x-(detector_x/2))<user_x+(detector_x/2);x++){		//detectörün x boyuncaki uzunluğunu kontrol ettirdiğim loop
			for(;tempx-(region_x/2) < koordinatrx+(region_x/2);tempx++){		//seçili bölgenin x boyuncaki uzunluğunu kontrol ettirdiğim loop
				if((x-(detector_x/2))==tempx-(region_x/2)){		//detectörün bölge üzerinde x boyunca üst üste bindiği miktarı veren condition
					overlapx+=1;
					if(overlapx==1){
						upgr_x1=(x-(detector_x/2));
					}
				}
			}
		tempx=koordinatrx;			//yeni dikdörtgenin x merkezini giriyoruz
		}
		
		overlapy=0;
		for(;y-(detector_y/2)<user_y+(detector_y/2);y++){		//detectörün y boyuncaki uzunluğunu kontrol ettirdiğim loop
			for(;tempy-(region_y/2) < koordinatry+(region_y/2);tempy++){		//seçili bölgenin y boyuncaki uzunluğunu kontrol ettirdiğim loop
				if((y-(detector_y/2))==tempy-(region_y/2)){		//detectörün bölge üzerinde y boyunca üst üste bindiği miktarı veren condition
					overlapy+=1;
					if(overlapy==1){
						upgr_y1=(y-(detector_y/2));
					}
				}
			}
		tempy=koordinatry;		//yeni dikdörtgenin y merkezini giriyoruz
		}
		
		/*aşağıdaki şartta kesişme miktarı tek ve çift olması halinde marked regionun x ve y koordinatı olarak merkezini belirlediğim koşul*/	
		if(overlapx!=0 && overlapy!=0){							//marked region ile detektör arasında kesişim olması halindeki şart
			if((overlapx>0)&&(overlapx%2==1)){					
				koordinatrx=upgr_x1+((overlapx-1)/2);
			}
			if((overlapx>0)&&(overlapx%2==0)){
				koordinatrx=upgr_x1+(overlapx/2);
			}
		
			if((overlapy>0)&&(overlapy%2==1)){
				koordinatry=upgr_y1+((overlapy-1)/2);
			}
			if((overlapy>0)&&(overlapy%2==0)){
				koordinatry=upgr_y1+(overlapy/2);
			}
		}
		
		if((user_x+detector_x/2)>board_x || (user_y+detector_y/2)>board_y || (user_x-detector_x/2)<0 || (user_y-detector_y/2)<0){
			 control=1;
			 printf("Error, move is not valid. Try again. Attempts remaining: %d \n",attempts_remaining);
		}

		if((overlapx==0 || overlapy==0) && control==0){			//board içinde marked region ile alakasız bir koordinat girilirse işleyecek olan koşul
			attempts_remaining-=1;
			printf("You missed the target, attempts remaining: %d \n",attempts_remaining);
		}
		
		if(overlapx==region_x && overlapy==region_y){		//oyunu kazanma ve kazandığımızı yazdırma şartı
			printf("You win...Congralations\n");
			a=2;
		}
		
		if((overlapx>0 && overlapy>0) && a!=2 ){			//marked regionda belli bir kısımda kesişme olursa yazdırılıp can eksiltilicek şart
			attempts_remaining-=1;
			printf("Partial hit! marked region was shirked to [%d x %d], detector was shirked to [%d x %d] attempts remaining: %d \n",overlapx,overlapy,detector_x,detector_y,attempts_remaining);
		}
		
		if(attempts_remaining==0){					//oyun hakkımız tükendiğinde loopu bitirip kaybettiğimizi yazdırma şartı
			printf("You lose ! Please try again.\n");
			a=2;
		}	
		
		if(overlapx>0 && overlapy>0){		//detektörün boyutunu yarıya düşürüp yeni marked regionun sizeını değiştirdiğimiz koşul
			detector_x/=2;
			detector_y/=2;
			region_x=overlapx;
			region_y=overlapy;
		}
	}
return 0;
}

/*float kullanmadan int değerler kullandığım için arada bazı değerler için değer kaybı olmuştur*/

