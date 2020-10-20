#include <libipd.h>


/*
 * 11.a.1
 * The awful truth about int in C
 * Not every integer can fit in a C int
 * An int is stored in a finite number of bits
 * Int has finite range: 32-bit int range from -2^31 to 2^31-1
 * <limits.h> INT_MIN , INT_MAX, out of range cause undefined behavior
 *
 *
 * char             1 byte	         -128 to 127 or 0 to 255
 * unsigned char	1 byte	         0 to 255
 * signed char	    1 byte	         -128 to 127
 * int	            2 or 4 bytes	 -32,768 to 32,767 or -2,147,483,648 to 2,147,483,647
 * unsigned int	    2 or 4 bytes	 0 to 65,535 or 0 to 4,294,967,295
 * short	        2 bytes	         -32,768 to 32,767
 * unsigned short	2 bytes	         0 to 65,535
 * long	            bytes or (4bytes for 32 bit OS)	-9223372036854775808 to 9223372036854775807
 * unsigned long	8 bytes	         0 to 18446744073709551615
 *
 *11.a.2
 * What is undefined behavior?
 * it's an error that computer doesn't notice
 * no error message or throw exception, it will keep running and give some nonsense
 * one UB makes everything UB
 * The underlying machine does certain things like wrapping, C doesn't.
 */
struct circle
{
    double x, y, radius;
};

// Scales the radius of circle `*p` by factor `f`.
void scale_circle(struct circle* p, double f)
{
    if(p){
        double old_radius = p->radius;
        double new_radius = f * old_radius;

        if (p != NULL && old_radius != new_radius) {
            p->radius = new_radius;
        }
    }

}

int main(void)
{
    struct circle my_circle = {
            .x      = 10,
            .y      = 20,
            .radius = 7,
    };

    scale_circle(&my_circle, 2);
    scale_circle(NULL,       3);
    scale_circle(&my_circle, 4);

    CHECK_DOUBLE( my_circle.radius, 56 );
}