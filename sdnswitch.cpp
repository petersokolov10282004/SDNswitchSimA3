#include <iostream>
#include <cstdint>

struct ethernet_header {
};

struct ipv6_header {
    
};

struct tcp_header {
    uint16_t src_port; //16 bits
    uint16_t dest_port; //16 bits
    uint32_t seq_num; //32 bits
    uint32_t ack_num; //32

    //starts with lsb so offset is bits 0-3
    uint16_t data_offset : 4;
    uint16_t reserved    : 4;
    uint16_t flags       : 8;

    uint16_t window;      // 16 bits
    uint16_t checksum;    // 16 bits
    uint16_t urgent_ptr;  // 16 bits: only valid when URG flag is set
} __attribute__((packed));

struct udp_header {
    uint16_t src_port;  // 16 bits
    uint16_t dst_port;  // 16 bits
    uint16_t length;    // 16 bits: total length of header + data in bytes
    uint16_t checksum;  // 16 bits
} __attribute__((packed));
