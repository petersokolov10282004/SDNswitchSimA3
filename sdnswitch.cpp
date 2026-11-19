#include <iostream>
#include <cstdint>

struct ethernet_header {
    uint8_t dst_mac[6];
    uint8_t src_mac[6];
    uint16_t ether_type;
} __attribute__((packed));

struct ipv6_header {
    uint32_t version : 4;
    uint32_t traffic_class : 8;
    uint32_t flow_label : 20;

    uint16_t payload_len;
    
    uint8_t next_header;
    uint8_t hop_limit;

    uint8_t src_addr[16];
    uint8_t dst_addr[16];


} __attribute__((packed));

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
