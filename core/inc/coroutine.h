/**
  ******************************************************************************
  * @file coroutine.h
  * @author lx
  * @version v1.0
  * @date 2026-01-09
  * @brief
 =============================================================================
                     #####  #####
 =============================================================================

  ******************************************************************************
  * @attention
  *
  ******************************************************************************
  */

#ifndef _COROUTINE_H_
#define _COROUTINE_H_

/* Includes ------------------------------------------------------------------*/

/**
 * @brief 声明协程的开始宏。
 * @note 需要与__COROUTINE_END成对使用，且必须在同一程序块内。
 * @param
 * @retval
 */
#define __COROUTINE_BEGIN()                                                                        \
    {                                                                                              \
        static int __coroutineExpression = 0;                                                      \
        switch (__coroutineExpression) {                                                           \
            case 0:

/**
 * @brief 创建阻塞条件，若条件不满足则程序会阻塞在该位置，若条件满足则程序会向下执行。
 * @note 必须在__COROUTINE_BEGIN和__COROUTINE_END之间使用。
 * @param condition:阻塞条件。
 * @retval
 */
#define __COROUTINE_WAIT_UNTIL(condition)                                                          \
    do {                                                                                           \
        __coroutineExpression = __LINE__;                                                          \
        case __LINE__:;                                                                            \
            if (!(condition)) {                                                                    \
                return;                                                                            \
            }                                                                                      \
    } while (0)

/**
 * @brief 声明协程的结束宏。
 * @note 需要与__COROUTINE_BEGIN成对使用，且必须在同一程序块内。
 * @param
 * @retval
 */
#define __COROUTINE_END()                                                                          \
    }                                                                                              \
    __coroutineExpression = 0;                                                                     \
    }

#endif // _COROUTINE_H_
