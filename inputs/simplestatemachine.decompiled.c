/* o_d0c7d58c782c4d8b3ce53224c70b8682(char) */

undefined8 o_d0c7d58c782c4d8b3ce53224c70b8682(char param_1)

{
  if (o_eb44246848628a2dc9fa6bc1de65a6d6 == 1) {
LAB_0010084b:
    if (param_1 == 'B') {
      return 0x59;
    }
    if (param_1 == 'C') {
      return 0x5a;
    }
    if (param_1 == 'A') {
      o_eb44246848628a2dc9fa6bc1de65a6d6 = 3;
      return 0x5a;
    }
    o_9b2565981764d034b75a93f83554736f();
  }
  else {
    if (o_eb44246848628a2dc9fa6bc1de65a6d6 < 2) {
      if (o_eb44246848628a2dc9fa6bc1de65a6d6 != 0) {
        return 0;
      }
      if (param_1 == 'B') {
        o_eb44246848628a2dc9fa6bc1de65a6d6 = 2;
        return 0x59;
      }
      if (param_1 == 'C') {
        return 0x5a;
      }
      if (param_1 == 'A') {
        o_eb44246848628a2dc9fa6bc1de65a6d6 = 1;
        return 0x58;
      }
      o_9b2565981764d034b75a93f83554736f();
      goto LAB_0010084b;
    }
    if (o_eb44246848628a2dc9fa6bc1de65a6d6 != 2) {
      if (o_eb44246848628a2dc9fa6bc1de65a6d6 != 3) {
        return 0;
      }
      goto LAB_001008c2;
    }
  }
  if (param_1 == 'B') {
    return 0x59;
  }
  if (param_1 == 'C') {
    o_eb44246848628a2dc9fa6bc1de65a6d6 = 0;
    return 0x5a;
  }
  if (param_1 == 'A') {
    return 0x5a;
  }
  o_9b2565981764d034b75a93f83554736f();
LAB_001008c2:
  if (param_1 == 'B') {
    return 0x59;
  }
  if (param_1 < 'C') {
    if (param_1 == 'A') {
      return 0x5a;
    }
  }
  else {
    if (param_1 == 'C') {
      o_eb44246848628a2dc9fa6bc1de65a6d6 = 0;
      return 0x5a;
    }
    if (param_1 == 'Q') {
      return 0x41;
    }
  }
  o_9b2565981764d034b75a93f83554736f();
  return 0;
}

void main(void)

{
  long in_FS_OFFSET;
  char local_16;
  char local_15;
  int local_14;
  undefined8 local_10;
  
  local_10 = *(undefined8 *)(in_FS_OFFSET + 0x28);
  while( true ) {
    local_16 = 0;
    local_14 = scanf("%c",&local_16);
    if (local_14 == -1) break;
    if ('@' < local_16) {
      local_15 = o_d0c7d58c782c4d8b3ce53224c70b8682(local_16);
      printf("%c\n",(ulong)(uint)(int)local_15);
      fflush(stdout);
    }
  }
                    /* WARNING: Subroutine does not return */
  exit(0);
}


