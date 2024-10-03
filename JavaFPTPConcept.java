import java.util.Random;

public class Main {
    public static void main(String[] args) {
        Random rand = new Random();
        int avgpop = 50000;
        int totaldists = 235;
        
        int partycount = 10;
        int[][] districts = new int[totaldists][partycount];
        
        int[] pollget = new int[partycount];
        int totpol = 0;
        int temp =0;
        for(int i=0; i!=partycount; i++)
        {
            
            pollget[i] = rand.nextInt(100);
            totpol+= pollget[i];
        }
        
        for(int i=0; i!=partycount;i++)
        {
            temp =0;
            temp = pollget[i];
            pollget[i] =0;
            pollget[i] = ((temp+1)*100)/ totpol;
        }
        
        int[] seats = new int[partycount];
        int[] votestotal = new int[partycount];

        int totalpop = 0;
        int[] vopercent = new int[partycount];
        int[] spercent = new int[partycount];
        
        

        for (int i = 0; i < totaldists; i++) {
            for (int b = 0; b < partycount; b++) {
                districts[i][b] = ((rand.nextInt(avgpop)+1)*pollget[b])/totaldists;
                
            }
            
        }

        int winnum = 6, winvotes = 0;

        for (int i = 0; i < totaldists; i++) {
            winnum = 6;
            winvotes = 0;
            for (int b = 0; b < partycount; b++) {
                if (districts[i][b] >= winvotes) {
                    winvotes = districts[i][b];
                    winnum = b;
                }
            }
            seats[winnum]++;
        }

        for (int i = 0; i < totaldists; i++) {
            for (int b = 0; b < partycount; b++) {
                votestotal[b] += districts[i][b];
            }
        }

        for (int i = 0; i < partycount; i++) {
            totalpop += votestotal[i];
        }

        for (int i = 0; i < partycount; i++) {
            vopercent[i] = (votestotal[i] * 100) / totalpop;
            spercent[i] = (seats[i] * 100) / totaldists;
            if(seats[i] >0){
            System.out.println(votestotal[i] + " votes (" + vopercent[i] + "%), " + seats[i] + " seats (" + spercent[i] + "%)");
            }
        }
    }
}

