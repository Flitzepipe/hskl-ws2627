package kwicSharedData;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Iterator;

public class KwicSharedData {
	public static ArrayList<Line> lines = new ArrayList<Line>();
	
	public static void main(String[] args){	
		readKwicFile("test.txt"); 
		createCircularShifts();
		sort();
		print();
	}
	
	private static void readKwicFile(String filename){
		BufferedReader br;
		String stringLine;
		String[] lineArray;
		Line newLine;
		Word newWord;
		
		try{
			br = new BufferedReader(new FileReader(filename));
			while( (stringLine=br.readLine()) != null ){
				lineArray = stringLine.split("\\s");
				newLine = new Line();
				for(int i=0; i<lineArray.length; i++){
					newWord = new Word();
					newWord.content = lineArray[i];
					newLine.words.add(newWord);
				}
				lines.add(newLine);
			}
		} catch (IOException e) {
		}

	}
	
	/* Erzeugt für jede Zeile in lines alle zirkulären Verschiebungen */
	private static void createCircularShifts(){
		int noOfLines = lines.size();
		for(int i=0; i<noOfLines; i++){
			createLineShifts(lines.get(i));
		}
	}
		
	/* Erzeugt für eine Zeile alle zirkulären Verschiebungen 
	 * und fügt sie in die Liste "lines" ein */
	private static void createLineShifts(Line currentLine){
		Line newLine;
		int nrWords = currentLine.words.size();
		for(int i=1; i<nrWords; i++){
			newLine = new Line();
			for (int j=i; j<nrWords; j++){
				newLine.words.add(currentLine.words.get(j));
			}
			for (int j=0; j<i; j++){
				newLine.words.add(currentLine.words.get(j));
			}
			lines.add(newLine);
		}
	}
	
	/* Sortiert die Zeilen (Bubble Sort).
	 * Verwendet zum Vergleich der Zeilen die Methode "isGreater" */
	private static void sort(){
		
		boolean stillChanges = true;
		Line intermediate;
		
		while(stillChanges){
			stillChanges=false;
			for (int i=0; i<lines.size() - 1; i++){
				if(isGreater(lines.get(i), lines.get(i+1))){
					intermediate = lines.get(i);
					lines.set(i, lines.get(i+1));
					lines.set(i+1, intermediate);
					stillChanges=true;
				}
			}
		}
	}
	
	
	/* Vergleicht zwei Zeilen. Liefert true, wenn line1 gemäß
	 * alphabetischem Vergleich nach line2 steht.
	 * Z. B. ist die Zeile "abc" größer als "aac" */
	private static boolean isGreater(Line line1, Line line2){
		
		boolean isGreater = false;
		boolean answerFound = false;
		Iterator<Word> it1 = line1.words.iterator();
		Iterator<Word> it2 = line2.words.iterator();
		
		while(!answerFound){
			
			if(it1.hasNext()){
				
				if(it2.hasNext()){
					int result = it1.next().content.compareToIgnoreCase(it2.next().content);
					if(result!=0){
						answerFound=true;
						isGreater=(result>0);
					}
				} else {
					isGreater=true;
					answerFound=true;
				}
				
			} else {
				isGreater=false;
				answerFound=true;
			}
			
		} // end while
		
		return isGreater;
	}
	

	private static void print(){
		for(Line currentLine:lines){
			for(Word currentWord:currentLine.words){
				System.out.print(currentWord.content + " ");
			}
			System.out.println();
		}
	}

}
