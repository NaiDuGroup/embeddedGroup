
/*
 * minunit.h
 *
 * Created: 12/19/2019 10:23:47
 *  Author: aleks
 */ 
 #define MU_ASSERT(message, test) do { if (!(test)) return message; }while (0)
 #define MU_RUN_TEST(test) do { char *message = test(); tests_run++; \
 if (message) return message; } while (0)
 extern int tests_run;