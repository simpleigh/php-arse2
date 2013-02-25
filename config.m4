PHP_ARG_ENABLE(arse2, whether to enable arse2 support,
[  --enable-arse2           Enable arse2 support])

if test "$PHP_ARSE2" != "no"; then
  PHP_NEW_EXTENSION(arse2, arse2.c, $ext_shared)
fi
