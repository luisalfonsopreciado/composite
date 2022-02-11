#include <cos_stubs.h>
#include <pong.h>

COS_SERVER_3RET_STUB(int, pong_argsrets)
{
	return pong_argsrets((int)p0, (int)p1, (int)p2, (int)p3, (word_t *)r1, (word_t *)r2);
}

COS_SERVER_3RET_STUB(long long, pong_widerets)
{
	long long p0d, p1d;
	long long ret;

	COS_ARG_WORDS_TO_DWORD(p0, p1, p0d);
	COS_ARG_WORDS_TO_DWORD(p2, p3, p1d);
	ret = pong_widerets(p0d, p1d);
	*r1 = (ret >> 32);
	*r2 = (ret << 32) >> 32;

	return 0;
}

COS_SERVER_3RET_STUB(int, pong_subset)
{
	return pong_subset((unsigned long)p0, (unsigned long)p1, (unsigned long *)r1);
}

COS_SERVER_3RET_STUB(thdid_t, pong_ids)
{
	return pong_ids((compid_t *)r1, (compid_t *)r2);
}

COS_SERVER_STUB(int, pong_wideargs)
{
#if defined(__WORD_SIZE_64__)
	return pong_wideargs(p0, p1);
#else
	long long p0d, p1d;

	COS_ARG_WORDS_TO_DWORD(p0, p1, p0d);
	COS_ARG_WORDS_TO_DWORD(p2, p3, p1d);
	return pong_wideargs(p0d, p1d);
#endif
}