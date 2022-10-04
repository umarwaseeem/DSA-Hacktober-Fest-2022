public class StringReversal {

	public static void main(String[] args) {

		String str = "Hello World";

		System.out.println("Original string : " + str);
		
		//convert string to character array
		char[] strArr = str.toCharArray();
		
		//create a new array which will contain characters in reversed order
		char[] revArr = new char[strArr.length];

		for (int i = strArr.length, j = 0; i > 0; i--, j++) {
			revArr[j] = strArr[i - 1];
		}

		String revStr = new String(revArr);
		System.out.println("Reversed string : " + revStr);

	}
}
