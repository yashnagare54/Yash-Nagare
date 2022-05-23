import java.util.Scanner;
public class HeapSort 
{ 
    public void sort(int arr[]) 
    { 
        int n = arr.length; 
  
        
        for (int i = n / 2 - 1; i >= 0; i--) 
            heapify(arr, n, i); 
  
        
        for (int i=n-1; i>=0; i--) 
        { 
           
            int temp = arr[0]; 
            arr[0] = arr[i]; 
            arr[i] = temp; 
  
           
            heapify(arr, i, 0); 
        } 
    } 
	
    void heapify(int arr[], int n, int i) 
    { 
        int largest = i;  
        int l = 2*i + 1;  
        int r = 2*i + 2;  
  
        if (l < n && arr[l] > arr[largest]) 
            largest = l; 
  
        
        if (r < n && arr[r] > arr[largest]) 
            largest = r; 
  
       
        if (largest != i) 
        { 
            int swap = arr[i]; 
            arr[i] = arr[largest]; 
            arr[largest] = swap; 
  
             
            heapify(arr, n, largest); 
        } 
    } 
  
    
    static void printArray(int arr[]) 
    { 
        int n = arr.length; 
        for (int i=0; i<n; ++i) 
            System.out.print(arr[i]+" "); 
        System.out.println(); 
         System.out.print("\nMinimum:"+arr[0]+"\nMaximum:"+arr[n-1]);
    } 
  
  
    public static void main(String args[]) 
    { 
		System.out.print("Enter Total Number of Subjects: ");
        int n;
		Scanner s=new Scanner(System.in);
	
	n=s.nextInt();
		int arr[]=new int[n];
		
		for(int i=0; i<n; i++)
		{
		        System.out.println("Enter the Marks: ");
				arr[i]=s.nextInt();
		}
		HeapSort ob = new HeapSort(); 
        ob.sort(arr); 
  
        System.out.println("Sorted array is"); 
        printArray(arr);
        
    } 
}