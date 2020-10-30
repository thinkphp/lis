package main

import "fmt"

func findMinMax(v [100]int, size int) (max, pos int) {

     max = 0
     
     pos = -1

     for i := 0; i < size;i++ {

         if v[i] > max {

            max = v[i]

            pos = i
         }
     }

     return 
}

func dynamic_programming(seq []int, n int) (out []int){

     var max int                
    
     lens := [100]int{}          

     lens[ n - 1 ] = 1    

     for i := n - 2; i >= 0; i-- {

         max = 0

         for j:=i+1; j < n; j++ {

             if seq[ i ] <= seq[ j ] && lens[ j ] > max {

                max = lens[j]
             } 
         }

         lens[i] = 1 + max;
     }     

     sol := []int{}

     maxx, pos := findMinMax(lens, n)

     sol = append(sol, seq[pos])

     fmt.Printf("Length -> %d\nLongest Increasing Subsequence -> ", maxx)

     maxx--

     for i := pos + 1; i < n; i++ {

         if( seq[i] >= seq[pos] && maxx == lens[i] ) {

            sol = append( sol, seq[ i ] )

            maxx--
         } 
     }
     
     return sol
}

func main() {

     var seq = []int{50, -1, 3, 10, 7, 40, 80}      

     size := len( seq )
     
     fmt.Println(dynamic_programming(seq, size))
}
