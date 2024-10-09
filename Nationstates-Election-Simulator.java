import java.util.*;

public class Main
{
	public static void main(String[] args) {
	    Random rand = new Random();
	    
	    double population= 7000000;
	    double divisor= 50000;
	    
	    
	    
	    
	    int numofparties = 6; // last party is always independent
	    
		double[] parties = new double[numofparties];
		double[] votes = new double[numofparties];
		double[] seats = new double[numofparties];
		String[] names = {"Daimong National Democratic Party", "Liberal Party of Daimong", "Socialists and Democrats of Daimong", "Alliance of The People", "Unity Party of Daimong", "Independents"};
		
		double totseats = 0, totvotes = 0;
		
		
		double[][] spregpp = new double[6][7]; // seats per region per party
		double[][] vpregpp = new double[6][7]; // votes per region per party
		
		
		
		double[]regpercent = {0.28,0.22,0.19,0.13,0.09,0.06,0.03};
		
		double[] regpop = new double[7];
		for(int i=0; i< regpop.length;i++){
		    regpop[i] = Math.round(population*regpercent[i]);
		}
		
		double[] avregpop = new double[7];
		for(int i=0; i<7;i++){
		    avregpop[i] = Math.round(regpop[i]*0.01); // VOTER TURNOUT MODIFIER(DEFAULT 0.025)
		}
		
		
		double numofdis = population/divisor;
		double[] districts = new double[7];
		
		for(int i=0; i<districts.length;i++) {
		    districts[i] = Math.round(numofdis*regpercent[i]);
		}
		
		
		double[][] parpop ={
		    {0.45,0.21,0.16,0.08,0.04,0.05}, // capital region
		    {0.50,0.18,0.09,0.07,0.06,0.1}, // Region I
		    {0.65,0.11,0.06,0.03,0.01,0.14}, //Region II
		    {0.63,0.13,0.06,0.04,0.03,0.11}, // Region III
		    {0.70,0.08,0.04,0.03,0.01,0.14}, // Region IV
		    {0.60,0.15,0.06,0.04,0.01,0.14}, // Region V
		    {0.80,0.06,0.05,0.03,0.01,0.05} // SAR
		}; // party popularity per region
		
		
		double[][][] regionalvotes = new double[7][][];
		double[][] seatperreg = new double[7][];
		int winnum = 7;
		double winvotes = 0;
		for(int i=0; i<7;i++){
		    regionalvotes[i] = new double[(int)districts[i]][6];
		    seatperreg[i] = new double[(int)districts[i]];
		}
		
		for(int i=0; i!= 7;i++) // region counter
		{
		    for(int b=0; b< districts[i];b++){ // district per region counter
		        for(int c=0; c< 6;c++){ // party vote adder
		        
		            regionalvotes[i][b][c] = ((double)rand.nextInt((int)avregpop[i]))*parpop[i][c];
		            votes[c] += regionalvotes[i][b][c];
		            totvotes+=regionalvotes[i][b][c];
		            
		            vpregpp[c][i]+= regionalvotes[i][b][c];
		        }
		        winnum = 7;
		        winvotes =0;
		        for(int c=0; c<6;c++){ // check who is highest
		            if(regionalvotes[i][b][c] >= winvotes) {
		                winnum =c;
		                winvotes = regionalvotes[i][b][c];
		                seatperreg[i][b] = c;
		                
		            }
		        }
		        seats[winnum]++;
		        totseats++;
		        spregpp[winnum][i]++;
		    }
		}
		
		String[] regnames = {"Capital", "Region I", "Region II", "Region III", "Region IV", "Region V", "SAR"};
		
		for(int i=0; i<7; i++){
		    System.out.println(regnames[i]+ ": " + districts[i]+ " Seats\n");
		}
		
		
		for(int i=0; i<6; i++){
		    
		    System.out.println("==============================");
		    System.out.println(names[i]+ ":\n" + seats[i]+ " Seats ("+ Math.round((seats[i]*100)/totseats)+"%)");
		    for(int b=0; b<7;b++){
		        System.out.println("\n    "+ regnames[b]+ ": "+ spregpp[i][b]);
		        System.out.println("    "+ regnames[b]+ ": "+ Math.round(vpregpp[i][b]));
		    }
		    
		    System.out.println("\n"+Math.round(votes[i])+ " Votes ("+Math.round((votes[i]*100)/totvotes)+"%)\n" );
		}
		
		System.out.println("\n\nTurnout: " + Math.round(totvotes)+ " (" + Math.round((totvotes*100)/(population/2))+ "%)");
		/*for(int i=0; i<7;i++){
		    System.out.println("\n====================\n"+ regnames[i]);
		    for(int b=0; b<districts[i]; b++){
		        System.out.println("\nDistrict "+ b);
		        for(int c=0; c< 6;c++){
		            System.out.print(names[c]+": "+ Math.round(regionalvotes[i][b][c]));
		            if(c == seatperreg[i][b]){
		                System.out.println(" - Winner");
		            } else
		            {
		                System.out.println("");
		            }
		        }
		    }
		}*/
		
	}
}
