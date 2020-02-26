#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct ConditionCodes {
    uint8_t     z:1;
    uint8_t     s:1;
    uint8_t     p:1;
    uint8_t     cy:1;
    uint8_t     ac:1;
    uint8_t     pad:3;
} ConditionCodes;

typedef struct State8080 {
    uint8_t     a;
    uint8_t     b;
    uint8_t     c;
    uint8_t     d;
    uint8_t     e;
    uint8_t     h;
    uint8_t     l;
    uint16_t    sp;
    uint16_t    pc;
    uint8_t     *memory;
    struct      ConditionCodes cc;
    uint8_t     int_enable;
} State8080;

void UnimplementedInstruction(State8080* state) {
    state->pc -= 1;
    printf("Error: Unimplemented Instruction\n");
    exit(1);
}


uint8_t CalculateParity(uint8_t n) {
    uint8_t parity = 0;

    for (int i = 0; i < 8; ++i) {
        if (n & 1) {
            ++parity;
        }
        n = n >> 1;
    }
    return (parity % 2 ? 1 : 0);
}

int SetArithmeticFlags(State8080 *state, uint16_t answer) {
    state->cc.z = ((answer & 0xFF) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.p = CalculateParity(answer & 0xFF);
    state->cc.cy = (answer > 0xFF);
    state->a = (answer & 0xFF);
    return 0;
}

int Emulate8080Op(State8080* state) {
    unsigned char *opcode = &state->memory[state->pc];

    switch(*opcode) {
        case 0x00: //NOP
            break; 
        case 0x01: //LXI B #$FFFF
            state->c = opcode[1];
            state->b = opcode[2];
            state->pc += 2;
            break;
        case 0x02: UnimplementedInstruction(state); break;
        case 0x03: UnimplementedInstruction(state); break;
        case 0x04: UnimplementedInstruction(state); break;
        case 0x05: UnimplementedInstruction(state); break;
        case 0x06: UnimplementedInstruction(state); break;
        case 0x07: UnimplementedInstruction(state); break;
        case 0x08: UnimplementedInstruction(state); break;
        case 0x09: UnimplementedInstruction(state); break;
        case 0x0A: UnimplementedInstruction(state); break;
        case 0x0B: UnimplementedInstruction(state); break;
        case 0x0C: UnimplementedInstruction(state); break;
        case 0x0D: UnimplementedInstruction(state); break;
        case 0x0E: UnimplementedInstruction(state); break;
        case 0x0F: UnimplementedInstruction(state); break;
        case 0x10: UnimplementedInstruction(state); break;
        case 0x11: UnimplementedInstruction(state); break;
        case 0x12: UnimplementedInstruction(state); break;
        case 0x13: UnimplementedInstruction(state); break;
        case 0x14: UnimplementedInstruction(state); break;
        case 0x15: UnimplementedInstruction(state); break;
        case 0x16: UnimplementedInstruction(state); break;
        case 0x17: UnimplementedInstruction(state); break;
        case 0x18: UnimplementedInstruction(state); break;
        case 0x19: UnimplementedInstruction(state); break;
        case 0x1A: UnimplementedInstruction(state); break;
        case 0x1B: UnimplementedInstruction(state); break;
        case 0x1C: UnimplementedInstruction(state); break;
        case 0x1D: UnimplementedInstruction(state); break;
        case 0x1E: UnimplementedInstruction(state); break;
        case 0x1F: UnimplementedInstruction(state); break;
        case 0x20: UnimplementedInstruction(state); break;
        case 0x21: UnimplementedInstruction(state); break;
        case 0x22: UnimplementedInstruction(state); break;
        case 0x23: UnimplementedInstruction(state); break;
        case 0x24: UnimplementedInstruction(state); break;
        case 0x25: UnimplementedInstruction(state); break;
        case 0x26: UnimplementedInstruction(state); break;
        case 0x27: UnimplementedInstruction(state); break;
        case 0x28: UnimplementedInstruction(state); break;
        case 0x29: UnimplementedInstruction(state); break;
        case 0x2A: UnimplementedInstruction(state); break;
        case 0x2B: UnimplementedInstruction(state); break;
        case 0x2C: UnimplementedInstruction(state); break;
        case 0x2D: UnimplementedInstruction(state); break;
        case 0x2E: UnimplementedInstruction(state); break;
        case 0x2F: UnimplementedInstruction(state); break;
        case 0x30: UnimplementedInstruction(state); break;
        case 0x31: UnimplementedInstruction(state); break;
        case 0x32: UnimplementedInstruction(state); break;
        case 0x33: UnimplementedInstruction(state); break;
        case 0x34: UnimplementedInstruction(state); break;
        case 0x35: UnimplementedInstruction(state); break;
        case 0x36: UnimplementedInstruction(state); break;
        case 0x37: UnimplementedInstruction(state); break;
        case 0x38: UnimplementedInstruction(state); break;
        case 0x39: UnimplementedInstruction(state); break;
        case 0x3A: UnimplementedInstruction(state); break;
        case 0x3B: UnimplementedInstruction(state); break;
        case 0x3C: UnimplementedInstruction(state); break;
        case 0x3D: UnimplementedInstruction(state); break;
        case 0x3E: UnimplementedInstruction(state); break;
        case 0x3F: UnimplementedInstruction(state); break;
        case 0x40: UnimplementedInstruction(state); break;
        case 0x41: UnimplementedInstruction(state); break;
        case 0x42: UnimplementedInstruction(state); break;
        case 0x43: UnimplementedInstruction(state); break;
        case 0x44: UnimplementedInstruction(state); break;
        case 0x45: UnimplementedInstruction(state); break;
        case 0x46: UnimplementedInstruction(state); break;
        case 0x47: UnimplementedInstruction(state); break;
        case 0x48: UnimplementedInstruction(state); break;
        case 0x49: UnimplementedInstruction(state); break;
        case 0x4A: UnimplementedInstruction(state); break;
        case 0x4B: UnimplementedInstruction(state); break;
        case 0x4C: UnimplementedInstruction(state); break;
        case 0x4D: UnimplementedInstruction(state); break;
        case 0x4E: UnimplementedInstruction(state); break;
        case 0x4F: UnimplementedInstruction(state); break;
        case 0x50: UnimplementedInstruction(state); break;
        case 0x51: UnimplementedInstruction(state); break;
        case 0x52: UnimplementedInstruction(state); break;
        case 0x53: UnimplementedInstruction(state); break;
        case 0x54: UnimplementedInstruction(state); break;
        case 0x55: UnimplementedInstruction(state); break;
        case 0x56: UnimplementedInstruction(state); break;
        case 0x57: UnimplementedInstruction(state); break;
        case 0x58: UnimplementedInstruction(state); break;
        case 0x59: UnimplementedInstruction(state); break;
        case 0x5A: UnimplementedInstruction(state); break;
        case 0x5B: UnimplementedInstruction(state); break;
        case 0x5C: UnimplementedInstruction(state); break;
        case 0x5D: UnimplementedInstruction(state); break;
        case 0x5E: UnimplementedInstruction(state); break;
        case 0x5F: UnimplementedInstruction(state); break;
        case 0x60: UnimplementedInstruction(state); break;
        case 0x61: UnimplementedInstruction(state); break;
        case 0x62: UnimplementedInstruction(state); break;
        case 0x63: UnimplementedInstruction(state); break;
        case 0x64: UnimplementedInstruction(state); break;
        case 0x65: UnimplementedInstruction(state); break;
        case 0x66: UnimplementedInstruction(state); break;
        case 0x67: UnimplementedInstruction(state); break;
        case 0x68: UnimplementedInstruction(state); break;
        case 0x69: UnimplementedInstruction(state); break;
        case 0x6A: UnimplementedInstruction(state); break;
        case 0x6B: UnimplementedInstruction(state); break;
        case 0x6C: UnimplementedInstruction(state); break;
        case 0x6D: UnimplementedInstruction(state); break;
        case 0x6E: UnimplementedInstruction(state); break;
        case 0x6F: UnimplementedInstruction(state); break;
        case 0x70: UnimplementedInstruction(state); break;
        case 0x71: UnimplementedInstruction(state); break;
        case 0x72: UnimplementedInstruction(state); break;
        case 0x73: UnimplementedInstruction(state); break;
        case 0x74: UnimplementedInstruction(state); break;
        case 0x75: UnimplementedInstruction(state); break;
        case 0x76: UnimplementedInstruction(state); break;
        case 0x77: UnimplementedInstruction(state); break;
        case 0x78: UnimplementedInstruction(state); break;
        case 0x79: UnimplementedInstruction(state); break;
        case 0x7A: UnimplementedInstruction(state); break;
        case 0x7B: UnimplementedInstruction(state); break;
        case 0x7C: UnimplementedInstruction(state); break;
        case 0x7D: UnimplementedInstruction(state); break;
        case 0x7E: UnimplementedInstruction(state); break;
        case 0x7F: UnimplementedInstruction(state); break;
        case 0x80: {//ADD B
            uint16_t answer = (uint16_t) state->a + (uint16_t) state->b;
            SetArithmeticFlags(state, answer);
            break;
        }
        case 0x81: {//ADD C
            uint16_t answer = (uint16_t) state->a + (uint16_t) state->c;
            SetArithmeticFlags(state, answer);
            break;
        }
        case 0x82: {//ADD D
            uint16_t answer = (uint16_t) state->a + (uint16_t) state->d;
            SetArithmeticFlags(state, answer);
            break;
        }
        case 0x83: {//ADD E
            uint16_t answer = (uint16_t) state->a + (uint16_t) state->e;
            SetArithmeticFlags(state, answer);
            break;
        }
        case 0x84: {//ADD H
            uint16_t answer = (uint16_t) state->a + (uint16_t) state->h;
            SetArithmeticFlags(state, answer);
            break;
        }
        case 0x85: {//ADD L
            uint16_t answer = (uint16_t) state->a + (uint16_t) state->l;
            SetArithmeticFlags(state, answer);
            break;
        }
        case 0x86: {//ADD M (HL combination register points to an address, add to a)
            uint16_t offset = (state->h<<8) | (state->l);
            uint16_t answer = (uint16_t) state->a + state->memory[offset];
            SetArithmeticFlags(state, answer);
            break;
        }
        case 0x87: {//ADD A 
            uint16_t answer = (uint16_t) state->a + (uint16_t) state->a;
            SetArithmeticFlags(state, answer);
            break;
        }
        case 0x88: {//ADC B
            uint16_t answer = (uint16_t) state->a + (uint16_t) state->b + (uint16_t) state->cc.cy;
            SetArithmeticFlags(state, answer);
            break;
        }
        case 0x89: {//ADC C
            uint16_t answer = (uint16_t) state->a + (uint16_t) state->c + (uint16_t) state->cc.cy;
            SetArithmeticFlags(state, answer);
            break;
        }
        case 0x8A: {//ADC D
            uint16_t answer = (uint16_t) state->a + (uint16_t) state->d + (uint16_t) state->cc.cy;
            SetArithmeticFlags(state, answer);
            break;
        }
        case 0x8B: {//ADC E
            uint16_t answer = (uint16_t) state->a + (uint16_t) state->e + (uint16_t) state->cc.cy;
            SetArithmeticFlags(state, answer);
            break;
        }
        case 0x8C: {//ADC H
            uint16_t answer = (uint16_t) state->a + (uint16_t) state->h + (uint16_t) state->cc.cy;
            SetArithmeticFlags(state, answer);
            break;
        }
        case 0x8D: {//ADC L
            uint16_t answer = (uint16_t) state->a + (uint16_t) state->l + (uint16_t) state->cc.cy;
            SetArithmeticFlags(state, answer);
            break;
        }
        case 0x8E: {//ADC M (HL combination register points to an address, add to a)
            uint16_t offset = (state->h<<8) | (state->l);
            uint16_t answer = (uint16_t) state->a + state->memory[offset] + (uint16_t) state->cc.cy;
            SetArithmeticFlags(state, answer);
            break;
        }
        case 0x8F: {//ADC A
            uint16_t answer = (uint16_t) state->a + (uint16_t) state->a + (uint16_t) state->cc.cy;
            SetArithmeticFlags(state, answer);
            break;
        }
        case 0x90: {//SUB B
            uint16_t answer = (uint16_t) state->a - (uint16_t) state->b;
            SetArithmeticFlags(state, answer);
            break;
        }
        case 0x91: {//SUB C
            uint16_t answer = (uint16_t) state->a - (uint16_t) state->c;
            SetArithmeticFlags(state, answer);
            break;
        }
        case 0x92: {//SUB D
            uint16_t answer = (uint16_t) state->a - (uint16_t) state->d;
            SetArithmeticFlags(state, answer);
            break;
        }
        case 0x93: {//SUB E
            uint16_t answer = (uint16_t) state->a - (uint16_t) state->e;
            SetArithmeticFlags(state, answer);
            break;
        }
        case 0x94: {//SUB H
            uint16_t answer = (uint16_t) state->a - (uint16_t) state->h;
            SetArithmeticFlags(state, answer);
            break;
        }
        case 0x95: {//SUB L
            uint16_t answer = (uint16_t) state->a - (uint16_t) state->l;
            SetArithmeticFlags(state, answer);
            break;
        }
        case 0x96: {//SUB M (HL combination register points to an address, sub from a)
            uint16_t offset = (state->h<<8) | (state->l);
            uint16_t answer = (uint16_t) state->a - state->memory[offset];
            SetArithmeticFlags(state, answer);
            break;
        }
        case 0x97: {//SUB A
            uint16_t answer = (uint16_t) state->a - (uint16_t) state->a;
            SetArithmeticFlags(state, answer);
            break;
        }
        case 0x98: {//SBB B
            uint16_t answer = (uint16_t) state->a - (uint16_t) state->b - (uint16_t) state->cc.cy;
            SetArithmeticFlags(state, answer);
            break;
        }
        case 0x99: {//SBB C
            uint16_t answer = (uint16_t) state->a - (uint16_t) state->c - (uint16_t) state->cc.cy;
            SetArithmeticFlags(state, answer);
            break;
        }
        case 0x9A: {//SBB D
            uint16_t answer = (uint16_t) state->a - (uint16_t) state->d - (uint16_t) state->cc.cy;
            SetArithmeticFlags(state, answer);
            break;
        }
        case 0x9B: {//SBB E
            uint16_t answer = (uint16_t) state->a - (uint16_t) state->e - (uint16_t) state->cc.cy;
            SetArithmeticFlags(state, answer);
            break;
        }
        case 0x9C: {//SBB H
            uint16_t answer = (uint16_t) state->a - (uint16_t) state->h - (uint16_t) state->cc.cy;
            SetArithmeticFlags(state, answer);
            break;
        }
        case 0x9D: {//SBB L
            uint16_t answer = (uint16_t) state->a - (uint16_t) state->l - (uint16_t) state->cc.cy;
            SetArithmeticFlags(state, answer);
            break;
        }
        case 0x9E: {//SBB M (HL combination register points to an address, sub from a)
            uint16_t offset = (state->h<<8) | (state->l);
            uint16_t answer = (uint16_t) state->a - state->memory[offset] - (uint16_t) state->cc.cy;
            SetArithmeticFlags(state, answer);
            break;
        }
        case 0x9F: {//SBB A
            uint16_t answer = (uint16_t) state->a - (uint16_t) state->a - (uint16_t) state->cc.cy;
            SetArithmeticFlags(state, answer);
            break;
        }
        case 0xA0: {//ANA B
            uint16_t answer = (uint16_t) state->a & (uint16_t) state->b;
            SetArithmeticFlags(state, answer);
            state->cc.cy = 0;
            break;
        }
        case 0xA1: {//ANA C
            uint16_t answer = (uint16_t) state->a & (uint16_t) state->c;
            SetArithmeticFlags(state, answer);
            state->cc.cy = 0;
            break;
        }
        case 0xA2: {//ANA D
            uint16_t answer = (uint16_t) state->a & (uint16_t) state->d;
            SetArithmeticFlags(state, answer);
            state->cc.cy = 0;
            break;
        }
        case 0xA3: {//ANA E
            uint16_t answer = (uint16_t) state->a & (uint16_t) state->e;
            SetArithmeticFlags(state, answer);
            state->cc.cy = 0;
            break;
        }
        case 0xA4: {//ANA H
            uint16_t answer = (uint16_t) state->a & (uint16_t) state->h;
            SetArithmeticFlags(state, answer);
            state->cc.cy = 0;
            break;
        }
        case 0xA5: {//ANA L
            uint16_t answer = (uint16_t) state->a & (uint16_t) state->l;
            SetArithmeticFlags(state, answer);
            state->cc.cy = 0;
            break;
        }
        case 0xA6: {//ANA M
            uint16_t offset = (state-> h<<8) | (state->l);
            uint16_t answer = (uint16_t) state->a & state->memory[offset];
            SetArithmeticFlags(state, answer);
            state->cc.cy = 0;
            break;
        }
        case 0xA7: {//ANA A
            uint16_t answer = (uint16_t) state->a & (uint16_t) state->a;
            SetArithmeticFlags(state, answer);
            state->cc.cy = 0;
            break;
        }
        case 0xA8: UnimplementedInstruction(state); break;
        case 0xA9: UnimplementedInstruction(state); break;
        case 0xAA: UnimplementedInstruction(state); break;
        case 0xAB: UnimplementedInstruction(state); break;
        case 0xAC: UnimplementedInstruction(state); break;
        case 0xAD: UnimplementedInstruction(state); break;
        case 0xAE: UnimplementedInstruction(state); break;
        case 0xAF: UnimplementedInstruction(state); break;
        case 0xB0: UnimplementedInstruction(state); break;
        case 0xB1: UnimplementedInstruction(state); break;
        case 0xB2: UnimplementedInstruction(state); break;
        case 0xB3: UnimplementedInstruction(state); break;
        case 0xB4: UnimplementedInstruction(state); break;
        case 0xB5: UnimplementedInstruction(state); break;
        case 0xB6: UnimplementedInstruction(state); break;
        case 0xB7: UnimplementedInstruction(state); break;
        case 0xB8: UnimplementedInstruction(state); break;
        case 0xB9: UnimplementedInstruction(state); break;
        case 0xBA: UnimplementedInstruction(state); break;
        case 0xBB: UnimplementedInstruction(state); break;
        case 0xBC: UnimplementedInstruction(state); break;
        case 0xBD: UnimplementedInstruction(state); break;
        case 0xBE: UnimplementedInstruction(state); break;
        case 0xBF: UnimplementedInstruction(state); break;
        case 0xC0: UnimplementedInstruction(state); break;
        case 0xC1: UnimplementedInstruction(state); break;
        case 0xC2: UnimplementedInstruction(state); break;
        case 0xC3: UnimplementedInstruction(state); break;
        case 0xC4: UnimplementedInstruction(state); break;
        case 0xC5: UnimplementedInstruction(state); break;
        case 0xC6: UnimplementedInstruction(state); break;
        case 0xC7: UnimplementedInstruction(state); break;
        case 0xC8: UnimplementedInstruction(state); break;
        case 0xC9: UnimplementedInstruction(state); break;
        case 0xCA: UnimplementedInstruction(state); break;
        case 0xCB: UnimplementedInstruction(state); break;
        case 0xCC: UnimplementedInstruction(state); break;
        case 0xCD: UnimplementedInstruction(state); break;
        case 0xCE: UnimplementedInstruction(state); break;
        case 0xCF: UnimplementedInstruction(state); break;
        case 0xD0: UnimplementedInstruction(state); break;
        case 0xD1: UnimplementedInstruction(state); break;
        case 0xD2: UnimplementedInstruction(state); break;
        case 0xD3: UnimplementedInstruction(state); break;
        case 0xD4: UnimplementedInstruction(state); break;
        case 0xD5: UnimplementedInstruction(state); break;
        case 0xD6: UnimplementedInstruction(state); break;
        case 0xD7: UnimplementedInstruction(state); break;
        case 0xD8: UnimplementedInstruction(state); break;
        case 0xD9: UnimplementedInstruction(state); break;
        case 0xDA: UnimplementedInstruction(state); break;
        case 0xDB: UnimplementedInstruction(state); break;
        case 0xDC: UnimplementedInstruction(state); break;
        case 0xDD: UnimplementedInstruction(state); break;
        case 0xDE: UnimplementedInstruction(state); break;
        case 0xDF: UnimplementedInstruction(state); break;
        case 0xE0: UnimplementedInstruction(state); break;
        case 0xE1: UnimplementedInstruction(state); break;
        case 0xE2: UnimplementedInstruction(state); break;
        case 0xE3: UnimplementedInstruction(state); break;
        case 0xE4: UnimplementedInstruction(state); break;
        case 0xE5: UnimplementedInstruction(state); break;
        case 0xE6: UnimplementedInstruction(state); break;
        case 0xE7: UnimplementedInstruction(state); break;
        case 0xE8: UnimplementedInstruction(state); break;
        case 0xE9: UnimplementedInstruction(state); break;
        case 0xEA: UnimplementedInstruction(state); break;
        case 0xEB: UnimplementedInstruction(state); break;
        case 0xEC: UnimplementedInstruction(state); break;
        case 0xED: UnimplementedInstruction(state); break;
        case 0xEE: UnimplementedInstruction(state); break;
        case 0xEF: UnimplementedInstruction(state); break;
        case 0xF0: UnimplementedInstruction(state); break;
        case 0xF1: UnimplementedInstruction(state); break;
        case 0xF2: UnimplementedInstruction(state); break;
        case 0xF3: UnimplementedInstruction(state); break;
        case 0xF4: UnimplementedInstruction(state); break;
        case 0xF5: UnimplementedInstruction(state); break;
        case 0xF6: UnimplementedInstruction(state); break;
        case 0xF7: UnimplementedInstruction(state); break;
        case 0xF8: UnimplementedInstruction(state); break;
        case 0xF9: UnimplementedInstruction(state); break;
        case 0xFA: UnimplementedInstruction(state); break;
        case 0xFB: UnimplementedInstruction(state); break;
        case 0xFC: UnimplementedInstruction(state); break;
        case 0xFD: UnimplementedInstruction(state); break;
        case 0xFE: UnimplementedInstruction(state); break;
        case 0xFF: UnimplementedInstruction(state); break;
    }
    state->pc += 1;
}


void main() {
    printf("cpu ran");
}