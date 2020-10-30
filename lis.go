package main

import "fmt"

func findMinMax(v [6]int) (max, pos int) {

     max = 0
     pos = -1

     for i:=0; i<len(v);i++ {

     	 if v[i] > max {

     	 	max = v[i]

     	 	pos = i
     	 }
     }
     return 
}

func main() {

     seq := [6]int{50, 3, 10, 7, 40, 80} 

     //lens := [6]int{0}
 
     var n, max int

     n = len(seq)     

     var lens [len(seq)]int     

     lens[ n - 1 ] = 1

     for i:=n - 2; i >= 0; i-- {

     	 max = 0

         for j:=i+1; j < n; j++ {

         	 if seq[ i ] <= seq[ j ] && lens[ j ] > max {

         	 	max = lens[j]
         	 } 
         }

         lens[i] = 1 + max;
     }     

     sol := []int{}

     maxx, pos := findMinMax(lens)

     sol = append(sol, seq[pos])

     fmt.Printf("Len -> %d\nSubseq -> ", maxx)

     maxx--

     for i:=pos+1; i < n; i++ {

     	 if(seq[i] >= seq[pos] && maxx == lens[i]) {

     	 	sol = append(sol, seq[i])
     	 	maxx--
     	 } 
     }
     
     fmt.Println(sol)
}
