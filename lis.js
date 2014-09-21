//Longest Increasing Subsequence

function LIS() {

       this.vec = []

       this.len = -1

       this.L = []

       this.output = []
}

LIS.prototype = {

       constructor: LIS,

       set: function( arr ) {

            this.vec = arr

            this.len = arr.length  

            for(var i = 0; i < this.len; i++) this.L[ i ] = 0

       },

       solve: function() {
      
            this.dynamic() 

            this.getSubseq() 

          return this            
       },  

       dynamic: function() {

            var n = this.len - 1, 

                max = 0;

                this.L[ n ] = 1
                
                for(var i = n - 1; i >= 0; i--) {

                        max = 0

                        for(var j = i + 1; j <= n; j++) {

                                if(this.vec[ j ] >= this.vec[ i ] && this.L[ j ] > max) {

                                   max = this.L[ j ] 
                                }
                        } 

                        this.L[ i ] = 1 + max 
                }
       },

       getSubseq: function() {

            var max = this.L[ 0 ], 

                posMax = 0, 

                output = [], 

                k = 0

                for(var i = 1; i < this.L.length; i++) {

                    if(this.L[ i ] > max) {

                       max = this.L[ i ]

                       posMax = i
                    } 
                }
                                
            output[ k++ ] = this.vec[ posMax ]

            max--

            for(var j = posMax + 1; j <= this.L.length; j++) {

                    if(this.vec[ j ] > this.vec[ posMax ] && this.L[ j ] == max) {

                          output[ k++ ] = this.vec[ j ]

                          max--
                    }
                    
            } 

            this.output = output
       },

       toString: function() {

                return this.output.toString()
       },

       toArray: function() {

                return this.output
       },

       getLength: function() {

                return this.output.length; 
       }        
}