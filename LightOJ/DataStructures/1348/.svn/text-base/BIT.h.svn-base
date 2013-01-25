
template<class T>
    class BIT {
        private:
        T bit[30005*2];
        int U;
        public:
        BIT() {
            ;
        }
        inline void init ( int U_ ) {
            SET ( bit,0 );
            U=U_;
        }

        inline void add ( int x, T v ) {
            while ( x < U )
                bit[x] += v, x += ( -x & x );
        }

        inline int get ( int x ) {
            T ans = 0;
            while ( x>0 )
                ans += bit[x], x -= ( -x & x );
            return ans;
        }
    };
// kate: indent-mode cstyle; indent-width 4; replace-tabs on; 
