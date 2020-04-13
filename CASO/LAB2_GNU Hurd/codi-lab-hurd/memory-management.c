#include <mach.h>
#include <mach_error.h>
#include <mach/mig_errors.h>
#include <mach/thread_status.h>
#include <mach/processor_info.h>
#include <stdio.h>
#include <stdlib.h>
#include <hurd.h>

#define N_ITER (4)


    processor_array_t processor_lists[N_ITER];
    mach_msg_type_number_t processor_listCnt;

int main ()
{
   int res, i;
   int * p;
   mach_port_t host_privileged_port;
   mach_port_t hostp2; 
   device_t device_privileged_port;

   res = get_privileged_ports(&host_privileged_port, &device_privileged_port);
   if (res != KERN_SUCCESS) {
      printf ("Error getting privileged ports (0x%x), %s\n", res, 
                mach_error_string(res));
      exit(1);
   }



   printf ("privileged ports: host 0x%x  devices 0x%x\n", 
                     host_privileged_port, device_privileged_port);

   i = 0;

   while (i < N_ITER) {

      printf ("%d: Getting processors at array 0x%x\n", i, processor_lists[i]);

      res = host_processors(host_privileged_port, 
                         &processor_lists[i], &processor_listCnt);
      if (res != KERN_SUCCESS) {
         printf ("Error getting host_processors (0x%x), %s\n", res,
                   mach_error_string(res));
         exit(1);
      }



      printf ("        processors at array 0x%x (count %d)\n",
                processor_lists[i], processor_listCnt);

      p = (int *) processor_lists[i];
      printf ("        Writing to memory area... 0x%x\n", p);
      *p = 73763;

      p = NULL;
      printf ("%d: Getting memory at location 0x%x\n", i, p);
      res = vm_map(mach_task_self(), (vm_address_t *) &p, 8192, 0, TRUE,
              MACH_PORT_NULL, 0, FALSE, VM_PROT_DEFAULT, VM_PROT_ALL, FALSE);
      if (res != KERN_SUCCESS) {
          printf ("Error getting memory with vm_map(0x%x), %s\n", res,
                    mach_error_string(res));
          exit(1);
      }
      printf ("        New vm_map memory at 0x%x\n", p);
      printf ("        Writing to memory area... 0x%x\n", p);
      *p = 53759;

    ++i;
   }
   return 0;
}

 


   

