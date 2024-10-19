
class Solution{
	public:
   	// Function to calculate sum of prime numbers up to n
   	long long int prime_Sum(int n){
   		vector<bool>vis(n+1, true); // Create a boolean array to mark prime numbers
   		long long int sum = 0; // Initialize sum as 0

   		// Finding all prime numbers using Sieve of Eratosthenes algorithm
   		for(int i = 2; i * i <= n; i++){
   			if(vis[i]){
   				for(int j = i*i; j <= n; j+=i){
   					vis[j] = false; // Mark multiples of i as false
   				}
   			}
   		}

   		// Calculating sum of prime numbers
   		for(int i = 2; i <= n; i++)
   			if(vis[i])
   				sum += i; // Adding prime numbers to sum

   		return sum; // Return the sum of prime numbers
   	}    
};