//For task 3

import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static BigInteger S(int k) {

        //if 0 <= k <= 1...
        if(k >= 0 && k <= 1)
            return BigInteger.valueOf(2); // then S(k) = 2

        //else if k > 1...
        BigInteger[] values = new BigInteger[k + 1]; //declare an array to store values
        values[0] = values[1] = BigInteger.valueOf(2); //set the base cases (if 0 <= k <= 1, then S(k) = 2)

        //and proceed with calculating the values for k > 1
        for(int i = 2; i <= k; ++i) { //calculate S(i) as long as i < k. i is like the original definition's k
            BigInteger sum = BigInteger.ZERO; /*and for each i (which increases, storing the summation values
                                                multiplied by 3, resulting in a greater and greater result as i
                                                increases)*/

            for(int j = 1; j < i; ++j) { //j < i prevents the program from traversing the array in its entirety
                sum = sum.add(values[j].multiply(values[i - j])); /*i is like the original definition's k and j is like i!
                                                                    so it's like if the indexes were i and k - i, respectfully*/
                /*i, in this for loop, is fixed. What changed is j, so that each iteration
                  makes so that the values considered "move" rightwards*/

                System.out.println(sum);
            }

            values[i] = sum.multiply(BigInteger.valueOf(3));
            System.out.println(" " + values[i] + "\n");
        }

        //return S(k)
        return values[k];
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Insert k: ");
        int k = scanner.nextInt();
        
        BigInteger result = S(k);
        System.out.println("S(" + k + ") equals: " + result);
        
        scanner.close();
    }
}
