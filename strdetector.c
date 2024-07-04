/**
 * @file        strdetect.c
 * @copyright
 * @license
 * @version     0.0.0
 * @date        07/03/2024
 * @author      Minh Phung Nhat
 *              Hung Pham Duc
 *              Khoi Nguyen Thanh
 * @brief       String "10110" detect
 *
 * @note        none
 *
 * @example
 *              #include <stdio.h>
 *              #include <stdint.h>
 *              #include "strdetector.h"
 *
 *              int main()
 *              {
 *                char str[]   = "1010110ABC10110110";
 *                uint32_t cnt = 0;
 *                strdetector_t sd;
 *                sd_init(&sd);
 *                for (int i = 0; i < sizeof(str) - 1; i++)
 *                {
 *                  if (sd_char_check(&sd, str[i]))
 *                  cnt++;
 *                }
 *                printf("Number of detected string: %d\n", cnt);
 *
 *                sd_reset(&sd);
 *                printf("Number of detected string: %d\n", sd_str_check(&sd, str, sizeof(str) - 1));
 *
 *                return 0;
 *              }
 */
/* Define to prevent recursive inclusion ------------------------------ */
#include "strdetector.h"
#include <stdio.h>
/* Private defines ---------------------------------------------------- */

/* Private enumerate/structure ---------------------------------------- */

/* Private macros ----------------------------------------------------- */

/* Public variables --------------------------------------------------- */

/* Private variables -------------------------------------------------- */

/* Private function prototypes ---------------------------------------- */

/* Function definitions ----------------------------------------------- */

uint32_t sd_init(strdetector_t *sd)
{
  if (sd == NULL)
    return SD_ERROR;
  sd->state = IDLE;
  return SD_SUCCESS;
}


uint32_t sd_reset(strdetector_t *sd)
{
  if (sd == NULL)
    return SD_ERROR;
  sd->state = IDLE;
  return SD_ERROR;
}


uint32_t sd_char_check(strdetector_t *sd, char c)
{
  if (sd == NULL)
    return SD_ERROR;

  if (c != '1' && c != '0')
  {
    sd->state = IDLE;
    return SD_ERROR;
  }

  switch (sd->state)
  {
  case IDLE:
    if (c == '1')
      sd->state++;
    break;

  case S0_1XXXX:
    if (c == '0')
      sd->state++;
    break;

  case S1_10XXX:
    if (c == '1')
      sd->state++;
    else
      sd->state = IDLE;
    break;

  case S2_101XX:
    if (c == '1')
      sd->state++;
    else
      sd->state = S1_10XXX;
    break;

  case S3_1011X:
    if (c == '0')
    {
      sd->state++;
      return SD_SUCCESS;
    }
    else
      sd->state = S0_1XXXX;
    break;

  case S4_10110:
    if (c == '1')
      sd->state = S2_101XX;
    else
      sd->state = IDLE;
    break;

  default: sd->state = IDLE; break;
  }

  return SD_ERROR;
}

uint32_t sd_str_check(strdetector_t *sd, char *str, uint32_t size)
{
  int cnt = 0;

  if (sd == NULL)
    return SD_ERROR;

  if (str == NULL)
    return SD_ERROR;

  for (int i = 0; i < size; i++)
  {
    if (sd_char_check(sd, *(str + i)))
      cnt++;
  }

  return cnt;
}


/* Private definitions ----------------------------------------------- */

/* End of file -------------------------------------------------------- */
