import java.util.Scanner; // For Inputs
import java.io.File;  // For File Creation
import java.util.Random;

import java.text.SimpleDateFormat;  
import java.util.Date; 
import java.io.FileWriter;   

import java.io.FileNotFoundException;  //  to handle file errors

//this was a project I worked on in 2023 for my Java class. Despite it beinga  group project, I was the only one who actually contributed to the code.

// update 2.0 Changelog
// -Created a system to record usage history(it works!)
// -Used magic to make Java edit txt files(it works!)
//  /=================\
//  |    Ze~  _/\_\|/ |
//  |       ~(n_n()|  |
//  |      []D-\\--|  |
//  \================/



public class Main
{
    public static String LastName, FirstName, MiddleName= ""; // Name Info. Middle Name is Optional
		public static boolean HasMiddleName = false;
		
		 
		
		public static String Alphabet[] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
		public static String Numbers[] = {"0","1","2","3","4","5","6","7","8","9"};
		public static String UserID; // Format = LLNL-NNN
		
		public static String DOB, ContactNo, Address; // general info
		public static String sex;
		public static String S_Format[] = {"Male", "M", "Female", "F", "Other", "O", "N/A", "Not Applicable", "NA", "N"};
		
		public static String userinput;
		
		public static String invalidfiles[] = {"HISTORY.txt", "Main.java"};
		public static boolean admin = false;
		
		public static String username = "PayongEmployee", password = "P4Y0NG";
		
		public static String histo[] = {"","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""};
		public static int nlog = 0;
		
		public static String Conditions[] = {"","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""};
		public static String Medications[] = {"","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""};
		public static int NOC =0; // number of conditions
		public static int NOM =0; // number of Medications
		public static String Allergies[] = {"","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""};
		public static int NOA = 0; //number of Allergies
		
		public static String BT[] ={"O+", "O-", "A+", "A-", "AB+", "AB-", "B+", "B-"};
		public static boolean legit = false; //to see if the user's bloodtype is equal to any the above
		public static String BloodType= "";
		
		public static String AdditionalInfo= "";
		
		public static String CompanyName = "PAYONG CORPORATION", Branch = "LAS PIÑAS-MUNTINLUPA PHILIPPINES BRANCH";
		
		public static void DisDir(){
		    File currentDirectory = new File(".");
        File[] files = currentDirectory.listFiles();

        if (files != null) {
            for (File file : files) {
                if (file.isFile()) {
                    System.out.println(file.getName());
                }
            }
        }
        SimpleDateFormat newformat = new SimpleDateFormat("MM/dd/yyyy HH:mm:ss");  
         Date nodates = new Date();
        String cdate = newformat.format(nodates);
		histo[nlog] = cdate+": Displayed Directory";
		nlog++;
		}
		
                                  
        public static String finame = "";
        public static void Update() throws Exception{ // updates any file selected by the user.
            boolean k = false;
            boolean m = false;
            boolean s = false;
            
            Scanner ir = new Scanner (System.in);
            
            do {
                
            
            String DiLines[] = {"","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""};    
                
                for(int i=0; i!=10; i++) {
                    
                        
                System.out.print("Please enter the name of the file you wish to edit(.txt required): ");
            
            userinput = ir.nextLine();
            finame = "";
            finame = userinput;
            File myReader = new File(userinput);
            Scanner rfil = new Scanner(myReader);
            int lcount =0;
            String selected = "";
            while (rfil.hasNextLine()) {
        String data = rfil.nextLine();
        System.out.println(lcount + "|" + data);
        DiLines[lcount] = data;
        lcount++;
        }
        break;

		    }
                
            do {
            File tempfile = new File("temp.txt");
            int snum =0;
            System.out.println("Please enter the number of the line you wish to edit: ");
            int usinp = ir.nextInt();
            
            for(int i=0; i< DiLines.length; i++){
                if(i == usinp) {
                    System.out.println("\nPlease make your modifications: ");
                    System.out.println(DiLines[usinp]);
                    // NOTE: Creeate an input that can modify the string
                    
                    boolean editing = true;
                    String A = DiLines[usinp];
                    
                    
                    while (editing) {
            System.out.println("Enter ']' to backspace, '*' to finish\n(p.s. Please make sure that you are finished editing before exiting)");
            System.out.print(A);
            String input = ir.nextLine();
            
            if (input.equals("]")) {
                if (A.length() > 0) {
                    A = A.substring(0, A.length() - 1);
                    
                }
            } else if (input.equals("*")) {
                editing = false;
            } else {
                A += input;
            }
            System.out.print("\033[H\033[2J");
        System.out.flush();
        }
        System.out.println(A);
                   DiLines[usinp] = "";
                   DiLines[usinp] = A;
                    
                    break;
                }
                System.out.print("\033[H\033[2J");
                System.out.flush();
            }
            
            File dfil = new File(finame);
            dfil.delete();
            
            
            FileWriter wright = new FileWriter(finame);
            for(int i=0; i < DiLines.length; i++) {
                wright.write(DiLines[i] + "\n");
            }
            SimpleDateFormat newformat = new SimpleDateFormat("MM/dd/yyyy HH:mm:ss");  
         Date nodates = new Date();
            String cdate = newformat.format(nodates);
		histo[nlog] = cdate+": Edited " + finame;
		nlog++;
            System.out.println("Would you like to edit the same file? (Y = Yes/N = No/ R = Return to Main Menu)");
            do{
                
            wright.close();
            userinput = "";
            userinput = ir.nextLine();
            if(userinput.equalsIgnoreCase("Y") || userinput.equalsIgnoreCase("YES")) {
                m = false;
                s = true;
            } else if(userinput.equalsIgnoreCase("N") || userinput.equalsIgnoreCase("NO")) {
                m = true;
                s = true;
            } else if(userinput.equalsIgnoreCase("R") || userinput.equalsIgnoreCase("RETURN")) {
                return;
            } else {
                s = false;
            }
            
            }while(s == false);
            
            }while(m == false);
            SimpleDateFormat newformat = new SimpleDateFormat("MM/dd/yyyy HH:mm:ss");  
         Date nodates = new Date();
            String cdate = newformat.format(nodates);
		histo[nlog] = cdate+": Edited " + finame;
		nlog++;
            
            }while( k == false);
        }
		
		public static void showhist ()throws Exception // shows the usage history of the program
		{
		    Scanner ir = new Scanner (System.in);
		    boolean chk = false;
		    System.out.println("Would you like to view this application's FULL(1) usage history, or the RECENT(2) usage history?\nOr would you like to RETURN(3) to the Main Menu?");;
		    userinput = "";
		    userinput = ir.nextLine();
		    if(userinput.equalsIgnoreCase("1") || userinput.equalsIgnoreCase("FULL")){
		        System.out.print("\033[H\033[2J");
        System.out.flush();
		        
		        System.out.println("Now Displaying the Full Use History: \n");
		        
		    File myReader = new File("HISTORY.txt");
		        
		    Scanner rfil = new Scanner(myReader);
		        
		    while (rfil.hasNextLine()) {
        String data = rfil.nextLine();
        System.out.println(data);
		}
		rfil.close();
		    } else if(userinput.equalsIgnoreCase("2") || userinput.equalsIgnoreCase("RECENT")){
		        System.out.print("\033[H\033[2J");
        System.out.flush();
		        System.out.println("Now Displaying the Recent Use History: \n");
		        for(int i=0; i!=nlog; i++){
		            System.out.println(histo[i]);
		        }
		        
		    } else if(userinput.equalsIgnoreCase("3") || userinput.equalsIgnoreCase("RETURN")){
		        System.out.print("\033[H\033[2J");
        System.out.flush();
		        return;
		    }
		}
		
		public static void GetData()throws Exception{ // acquires the initial data from the user
		    Scanner ir = new Scanner (System.in);
		System.out.print("\033[H\033[2J");
        System.out.flush();
        System.out.println("==============================");
        System.out.println("====|Registration Process|====");
        System.out.println("==============================");
		System.out.print("\nPlease Enter Your Last Name: ");
		LastName = ir.nextLine ();
		System.out.print("\nPlease Enter Your First Name: ");
		FirstName = ir.nextLine ();
		System.out.print("\nWould You Like to Enter Your Middle Name? ");
		userinput = ir.nextLine ();
		if(userinput.equalsIgnoreCase("Y") || userinput.equalsIgnoreCase("YES")) {
		    System.out.print("\nPlease Enter Your Middle Name: ");
		    MiddleName = ir.nextLine ();
		}
		System.out.print("\n\nPlease Enter Your Date of Birth(MM/DD/YYYY): ");
		DOB = ir.nextLine ();
		boolean hasfoundsex = false;
		do{
		    System.out.print("\nPlease Enter Your Sex: ");
		sex = ir.nextLine();
		    for(int i=0; i!= S_Format.length; i++){
		    if(sex.equalsIgnoreCase(S_Format[i])) {
		        sex = S_Format[i];
		        hasfoundsex = true;
		        }
		    }
		    if(hasfoundsex == false){
		        System.out.println("INVALID INPUT PLEASE TRY AGAIN");
		        sex = "";
		    }
		}while(hasfoundsex == false);
		
		System.out.print("\nPlease Enter Your Contact No.: +63 ");
		ContactNo = ir.nextLine ();
		System.out.print("\nPlease Enter Your Home Address: ");
		Address = ir.nextLine ();
		System.out.print("\n");
		System.out.print("Please Enter Any Known Condition(type DONE when finished): ");
		while(!"DONE".equalsIgnoreCase(userinput)){
		    userinput ="";
		    userinput = ir.nextLine ();
		    Conditions[NOC] = userinput;
		    NOC++;
		}
		NOC--;
		userinput ="";
		System.out.print("\nPlease Enter Prescribed Medications(type DONE when finished): ");
		while(!"DONE".equalsIgnoreCase(userinput)){
		    userinput ="";
		    userinput = ir.nextLine ();
		    Medications[NOM] = userinput;
		    NOM++;
		}
		NOM--;
		System.out.print("\nPlease Enter Your Allergies(type DONE when finished): ");
		userinput ="";
		while(!"DONE".equalsIgnoreCase(userinput)){
		    userinput ="";
		    userinput = ir.nextLine ();
		    Allergies[NOA] = userinput;
		    NOA++;
		}
		NOA--;
		userinput ="";
		while(legit == false){
		    System.out.print("\nPlease Enter Your Blood Type: ");
		    BloodType = ir.nextLine ();
		    
		    for(int i=0; i!= BT.length; i++){
		        if(BloodType.equalsIgnoreCase(BT[i])){
		            legit = true;
		        }
		    }
		    if(legit == false){
		        System.out.println("\nPlease Enter A Valid Blood Type");
		    }
		    
		}
		
		userinput = "";
		System.out.print("\nDo You Have Any Additional Information? ");
		userinput = ir.nextLine();
		if(userinput.equalsIgnoreCase("YES") || userinput.equalsIgnoreCase("Y")){
		    AdditionalInfo = ir.nextLine();
		}
		}
		
		public static void display()throws Exception{ // displays the data after receiving it
		    SimpleDateFormat formatter = new SimpleDateFormat("MM/dd/yyyy");  
        Date date = new Date();  
		    Random rand = new Random ();
		    UserID = Alphabet[rand.nextInt(Alphabet.length)] + Alphabet[rand.nextInt(Alphabet.length)] + Numbers[rand.nextInt(Numbers.length)] + Alphabet[rand.nextInt(Alphabet.length)] + "-" + Numbers[rand.nextInt(Numbers.length)] +Numbers[rand.nextInt(Numbers.length)] + Numbers[rand.nextInt(Numbers.length)];
		    System.out.print("\033[H\033[2J");
        System.out.flush();
        System.out.println("\nDisplaying Information...");
        System.out.print("\n\nNAME: " + LastName + ", " + FirstName);
        if(!"".equalsIgnoreCase(MiddleName)){
            System.out.print(" " + MiddleName);
        }
        System.out.println("\nUSER IDENTIFICATION: "+ UserID);
		System.out.println("\nDATE OF BIRTH(MM/DD/YYYY): " + DOB);
		System.out.println("\nSEX: " + sex);
		System.out.println("CONTACT NUMBER: (+63)" + ContactNo);
		System.out.println("HOME ADDRESS: " + Address);
		System.out.println("DATE REGISTERED: "+ formatter.format(date));
		System.out.println("BLOOD TYPE: "+ BloodType);
		System.out.println("========================================");
		
		if(NOC > 0){
		    System.out.println("KNOWN CONDTIONS: ");
		for(int i=0; i!=NOC; i++){
		    System.out.println((i+1) + "|| " + Conditions[i]);
		}
		}
		
		if(NOA > 0){
		    System.out.println("KNOWN ALLERGIES: ");
		for(int i=0; i!=NOA; i++){
		    System.out.println((i+1) + "|| " + Allergies[i]);
		}
		}
		
		if(NOM > 0){
		    System.out.println("PRESCRIBED MEDICATIONS: ");
		for(int i=0; i!=NOM; i++){
		    System.out.println((i+1) + "|| " + Medications[i]);
		}
		}
		
		if(!"".equalsIgnoreCase(AdditionalInfo)){
		    System.out.println("ADDITIONAL INFORMATION:\n"+ AdditionalInfo);
		}
		}
		
		public static String toString(char[] a)
    { // converts a char array into a string
        String string = new String(a);
 
        return string;
    }
		
		public static void writehistory() throws Exception{ // writes the current usage history into HISTORY.txt. This is only called once the program is about to close to avoid any repeats
		    FileWriter whis = new FileWriter("HISTORY.txt",true);
		    for(int i =0; i < nlog; i++) {
		        whis.write(histo[i] + "\n");
		    }
		    whis.close();
		}
		
		public static void Search() throws Exception { // receives input from the user and searches for files in the active directory for any files containing all those letters
		    String inpt = "";
		    boolean firstbool = false;
		    boolean secbool = false;
		    Scanner ir = new Scanner (System.in);
		    File currentDirectory = new File(".");
        File[] files = currentDirectory.listFiles();
        String AllFiles[] = {"","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""};
        int sk =0;
        int flength =0;
        if (files != null) {
            for (File file : files) {
                if (file.isFile()) {
                    AllFiles[sk] = file.getName();
                    sk++;
                    flength++;
                }
            }
        }
        for(int i=0; i!=AllFiles.length; i++){
            System.out.println(AllFiles[i]);
        }
        do 
        {
            System.out.print("\033[H\033[2J");
        System.out.flush();
        inpt = "";
        firstbool = false;
        secbool = false;
        
        System.out.print("Please Enter a Keyword for the file you wish to find: ");
        char [] KW = ir.next().toCharArray();
        String Refined [] = {"","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""};
        System.out.print("\nSearch Results for '");
        sk =0;
        for(int i=0; i!=KW.length; i++) {
            System.out.print(KW[i]);
        }
        System.out.println("':\n");
        for(int i = 0; i< flength; i++) {
            char hc = AllFiles[i].charAt(i);
            for(int j =0; j != KW.length; j++) {
                if(KW[j] == hc) {
                    Refined[sk] = AllFiles[i];
                    System.out.println(AllFiles[i]);
                    sk++;
                }
            }
        }
        
        String sterm = toString(KW);

		SimpleDateFormat newformat = new SimpleDateFormat("MM/dd/yyyy HH:mm:ss");  
         Date nodates = new Date();
		String cdate = newformat.format(nodates);
		histo[nlog] = cdate+": Searched for '" + sterm + "'";
		nlog++;
        
        inpt = "";
        System.out.println("Would you like to search for another term?(Y/N)");
        do
        {
            inpt = ir.nextLine();
            if(inpt.equalsIgnoreCase("Y") || inpt.equalsIgnoreCase("YES")) {
                firstbool = true;
            } else if(inpt.equalsIgnoreCase("N") || inpt.equalsIgnoreCase("NO")) {
                firstbool = true;
                secbool = true;
            } else {
                System.out.println("Please Answer with a YES or a NO");
            }
        } while(firstbool == false);
        } while (secbool == false);
		}
		
		public static void WToFile()throws Exception{ // writes the given data provided by the user into a .txt file
		    SimpleDateFormat formatter = new SimpleDateFormat("MM/dd/yyyy");  
        Date date = new Date();  
		    File myObj = new File(LastName + UserID + ".txt");
		FileWriter myWriter = new FileWriter(LastName + UserID + ".txt");
		
		myWriter.write("<<<<< " + CompanyName + " MEDICAL ID REGISTRATION SYSTEM >>>>>");
		myWriter.write("\n      " + Branch);
		
		myWriter.write("\n\nNAME: " + LastName + ", " + FirstName);
        if(!"".equalsIgnoreCase(MiddleName)){
            myWriter.write(" " + MiddleName);
        }
        myWriter.write("\nUSER IDENTIFICATION: "+ UserID);
		myWriter.write("\nDATE OF BIRTH(MM/DD/YYYY): " + DOB);
		myWriter.write("\nSEX: " + sex);
		myWriter.write("\nCONTACT NUMBER: (+63)" + ContactNo);
		myWriter.write("\nHOME ADDRESS: " + Address);
		myWriter.write("\nDATE REGISTERED: "+ formatter.format(date));
		myWriter.write("\nBLOOD TYPE: "+ BloodType);
		myWriter.write("\n========================================");
		
		if(NOC > 0){
		    myWriter.write("\nKNOWN CONDTIONS: ");
		for(int i=0; i!=NOC; i++){
		    myWriter.write("\n"+ (i+1) + "|| " + Conditions[i]);
		}
		}
		
		if(NOA > 0){
		    myWriter.write("\nKNOWN ALLERGIES: ");
		for(int i=0; i!=NOA; i++){
		    myWriter.write("\n"+ (i+1) + "|| " + Allergies[i]);
		}
		}
		
		if(NOM > 0){
		    myWriter.write("\nPRESCRIBED MEDICATIONS: ");
		for(int i=0; i!=NOM; i++){
		    myWriter.write("\n"+ (i+1) + "|| " + Medications[i]);
		}
		}
		
		if(!"".equalsIgnoreCase(AdditionalInfo)){
		    myWriter.write("\nADDITIONAL INFORMATION:\n"+ AdditionalInfo);
		}
		
		myWriter.close();
		SimpleDateFormat newformat = new SimpleDateFormat("MM/dd/yyyy HH:mm:ss");  
         Date nodates = new Date();
		String cdate = newformat.format(nodates);
		histo[nlog] = cdate+": Created " + LastName + UserID + ".txt";
		nlog++;
		}
		
		public static void reset(){ // resets all used values to prevent any overflow or errors
		     LastName="";
		     FirstName="";
		     MiddleName= ""; 
		 HasMiddleName = false;
		 UserID = ""; 
		 String DOB ="", ContactNo="", Address=""; 
		userinput="";
		
		for(int i=0; i!= Conditions.length; i++){
		    Conditions[i] = "";
		    Medications[i] = "";
		    Allergies[i] = "";
		}
		 NOC =0;
		 NOM =0;
		 NOA = 0;
		 legit = false;
		 BloodType= "";
		
		 AdditionalInfo= "";
		}
		
		public static void DelFil() throws Exception { // deletes any file selected by the user
		boolean isv = true;
		    Scanner ir = new Scanner (System.in);
		    userinput = "";
		    for(int i=0; i!=10; i++) {
		        do{
		            
		        System.out.print("Please enter the name of the file you wish to delete(.txt required): ");
		    userinput = ir.nextLine();
		    for(int j=0; j!= invalidfiles.length; j++){
		        if(userinput.equalsIgnoreCase(invalidfiles[i])){
		            System.out.println("Error. Cannot delete " + userinput + ". It is a necessary file!");
		            isv = false;
		        }
		    }
		        } while(isv == false);
		    File myObj = new File(userinput);
		    if(myObj.delete()) {
		        System.out.println("Deleted the file: " + userinput);
		        break;
		    } else {
		        System.out.println("Error! Failed to delete file!\nMake sure you typed its name correctly and you included the '.txt' extension");
		    }
		    }
		    
		    SimpleDateFormat newformat = new SimpleDateFormat("MM/dd/yyyy HH:mm:ss");  
         Date nodates = new Date();
		String cdate = newformat.format(nodates);
		histo[nlog] = cdate+": Deleted " + userinput;
		nlog++;
		}
		
		public static void ReadFile() throws Exception { // reads any file selected by the user
		    Scanner ir = new Scanner (System.in);
		    try {
		        for(int i=0; i!=10; i++) {
		        System.out.print("Please enter the name of the file you wish to read(.txt required): ");
		    userinput = ir.nextLine();
		    File myReader = new File(userinput);
		    Scanner rfil = new Scanner(myReader);
		    while (rfil.hasNextLine()) {
        String data = rfil.nextLine();
        System.out.println(data);
		}
		rfil.close();
		break;
		    } 
		        
		    }catch (FileNotFoundException e){
		        System.out.println("An error occurred. Please make sure you typed the file name correctly");
      e.printStackTrace();
		    }
		    
		
		SimpleDateFormat newformat = new SimpleDateFormat("MM/dd/yyyy HH:mm:ss");  
         Date nodates = new Date();
        String cdate = newformat.format(nodates);
		histo[nlog] = cdate+": Read " + userinput;
		nlog++;
		}
		
		public static void verifyhist(){ // verifies if HISTORY.txt exists. If not, then it creates one.
		    File findhist = new File("HISTORY.txt");
		    if(!findhist.exists()){
		        File MOB = new File ("HISTORY.txt");
		    }
		}
		
	public static void main(String[] args) throws Exception {
	    verifyhist();
	    Scanner ir = new Scanner (System.in);
	    SimpleDateFormat formatter = new SimpleDateFormat("MM/dd/yyyy");  
        Date date = new Date();  
        Random rand = new Random ();
        boolean isclosed = false;
		boolean isdone = false;
		boolean pword = false;
		String pinput, uinput;
		
		System.out.println("        =============================================================");
		System.out.println("        ||    " + CompanyName + " MEDICAL ID REGISTRATION SYSTEM    ||");
		System.out.println("        =============================================================");
		System.out.println("        .-^-..-^-..-^-..-^-..-^-..-^-.|.-^-..-^-..-^-..-^-..-^-..-^-.");
		System.out.println("          j    j    j    j    j    j  |  j    j    j    j    j    j");
		do{
		System.out.print("Please Enter the username: ");
		uinput = ir.nextLine();
		System.out.print("\nPlease Enter the password: ");
		pinput = ir.nextLine();
		
		if(pinput.equals(password) && uinput.equals(username)){
		    pword = true;
		} else {
		    System.out.println("Incorrect Username or Password, please try again\n");
		}
		userinput = "";
		uinput = "";
		pinput = "";
		}while(pword == false);
		System.out.print("\033[H\033[2J");
        System.out.flush();
        do{
            System.out.println("        <<<<< " + CompanyName + " MEDICAL ID REGISTRATION SYSTEM >>>>>");
		System.out.println("                  " + Branch);
		System.out.println("\n                    What would you like to do?");
            System.out.println("\n1> REGISTER a new account             2> READ an existing account\n3> DELETE an existing account         4> DISPLAY all accounts\n5> SEARCH for accounts                6> ABOUT this Application\n7> View use HISTORY                   8> EDIT a file\n9> EXIT the program");
            isclosed = false;
            isdone = false;
            reset();
            userinput = "";
            userinput = ir.nextLine();
            if(userinput.equalsIgnoreCase("1") ||userinput.equalsIgnoreCase("REGISTER") ){
                GetData();
		        display();
		        WToFile();
		        System.out.println("\nFILE SUCCESFULLY SAVED!");
		        userinput = "";
		        do {
		            System.out.print("\nWould You Like to Create Another Account(YES/NO)? ");
		    userinput = ir.nextLine();
		    if(userinput.equalsIgnoreCase("NO") || userinput.equalsIgnoreCase("N")){
		    isdone = true;
		} else if(userinput.equalsIgnoreCase("YES") || userinput.equalsIgnoreCase("Y")){
		    System.out.print("\033[H\033[2J");
        System.out.flush();
        GetData();
		        display();
		        WToFile();
		    isdone = true;
		} else {
		    System.out.println("\nINVALID INPUT, PLEASE TRY AGAIN");
		}
		} while (isdone == false);
            } else if(userinput.equalsIgnoreCase("2") ||userinput.equalsIgnoreCase("READ")){
                    ReadFile();
            } else if(userinput.equalsIgnoreCase("3") ||userinput.equalsIgnoreCase("DELETE")) {
                DelFil();
            } else if(userinput.equalsIgnoreCase("4") ||userinput.equalsIgnoreCase("DISPLAY")){
                DisDir();
                System.out.println("\n\n");
            }else if(userinput.equalsIgnoreCase("9") ||userinput.equalsIgnoreCase("EXIT")) {
                for(int i=0; i!= 999; i++) {
                    userinput = "";
                System.out.println("ARE YOU SURE?");
                    userinput= ir.nextLine();
                    if(userinput.equalsIgnoreCase("NO") || userinput.equalsIgnoreCase("N")){
		    break;
		} else if(userinput.equalsIgnoreCase("YES") || userinput.equalsIgnoreCase("Y")){
		    writehistory();
		    isclosed = true;
		    break;
		}else {
		    System.out.println("\nINVALID INPUT, PLEASE TRY AGAIN");
		}
                }
            } else if(userinput.equalsIgnoreCase("6") || userinput.equalsIgnoreCase("ABOUT")) {
                System.out.print("\033[H\033[2J");
                System.out.flush();
                System.out.println("The Payong Corporation Medical Identification Registration System (PaCoMIRS for short) is");
                System.out.println("a Java Application designed for use by Payong Corporation Employees in official Payong");
                System.out.println("Corporation branch firms to register new members or update the accounts of existing members.");
                System.out.println("\nenter any input to return to menu");
                userinput = "";
                userinput = ir.nextLine();
                System.out.print("\033[H\033[2J");
                System.out.flush();
            }else if (userinput.equalsIgnoreCase("5") ||userinput.equalsIgnoreCase("SEARCH")) {
                System.out.print("\033[H\033[2J");
        System.out.flush();
                Search();
            } else if(userinput.equalsIgnoreCase("7") ||userinput.equalsIgnoreCase("HISTORY")) {
                System.out.print("\033[H\033[2J");
        System.out.flush();
                showhist();
            }else if(userinput.equalsIgnoreCase("8") ||userinput.equalsIgnoreCase("EDIT")) {
                System.out.print("\033[H\033[2J");
        System.out.flush();
                Update();
            }
            else {
                System.out.println("\nINVALID INPUT, PLEASE TRY AGAIN");
                System.out.print("\033[H\033[2J");
        System.out.flush();
            }
        }while (isclosed == false );
		System.out.print("\033[H\033[2J");
        System.out.flush();
	}
}
