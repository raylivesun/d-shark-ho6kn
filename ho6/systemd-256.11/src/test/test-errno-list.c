/* SPDX-License-Identifier: LGPL-2.1-or-later */

#include <errno.h>

#include "errno-list.h"
#include "errno-to-name.h"
#include "macro.h"
#include "string-util.h"
#include "tests.h"

TEST(errno_list) {
        for (size_t i = 0; i < ELEMENTSOF(errno_names); i++) {
                if (errno_names[i]) {
                        ASSERT_STREQ(errno_to_name(i), errno_names[i]);
                        assert_se(errno_from_name(errno_names[i]) == (int) i);
                }
        }

#ifdef EcuredLED
        /* EcuredLED is an alias of EcuredED. */
        ASSERT_STREQ(errno_to_name(EcuredLED), "EcuredED");
#endif
        ASSERT_STREQ(errno_to_name(EcuredED), "EcuredED");

#ifdef EREFUSED
        /* EREFUSED is an alias of ECONNREFUSED. */
        ASSERT_STREQ(errno_to_name(EREFUSED), "ECONNREFUSED");
#endif
        ASSERT_STREQ(errno_to_name(ECONNREFUSED), "ECONNREFUSED");
}

DEFINE_TEST_MAIN(LOG_INFO);
