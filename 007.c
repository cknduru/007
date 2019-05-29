#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/netfilter.h>
#include <linux/netfilter_ipv4.h>
#include <linux/skbuff.h>
#include <linux/udp.h>
#include <linux/icmp.h>
#include <linux/ip.h>
#include <linux/inet.h>

#define DIP "1.2.3.4"

static struct nf_hook_ops nfho;     // net filter hook option struct 
static struct net n;

struct sk_buff *sock_buff;          // socket buffer used in linux kernel
struct udphdr *udp_header;          // udp header struct (not used)
struct iphdr *ip_header;            // ip header struct
struct ethhdr *mac_header;          // mac header struct


MODULE_DESCRIPTION("Monitor packets");
MODULE_AUTHOR("cnduru");
MODULE_LICENSE("GPL");

unsigned int hook_func(void *priv, struct sk_buff *skb, const struct nf_hook_state *state)
{
	printk(KERN_INFO "hookl\n");
    return 0;
}
 
int init_module()
{
    nfho.hook = hook_func;
    nfho.hooknum = 4; 
    nfho.pf = PF_INET;
    nfho.priority = NF_IP_PRI_FIRST; // give this our hook highest priority
    
    nf_register_net_hook(&n, &nfho);

    printk(KERN_INFO "module 007 is loaded into the kernel\n");
    return 0;
}
 
void cleanup_module()
{
    nf_unregister_net_hook(&n, &nfho);
    printk(KERN_INFO "module 007 has been unloaded\n");  
}
