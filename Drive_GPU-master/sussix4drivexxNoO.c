/* sussix4drivexxNoO.f -- translated by f2c (version 20100827).
   You must link the resulting object file with libf2c:
	on Microsoft Windows system, link with libf2c.lib;
	on Linux or Unix systems, link with .../path/to/libf2c.a -lm
	or, if you install libf2c.a in a standard place, with -lf2c -lm
	-- in that order, at the end of the command line, as in
		cc *.o -lf2c -lm
	Source for libf2c is in /netlib/f2c/libf2c.zip, e.g.,

		http://www.netlib.org/f2c/libf2c.zip
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal x[100000], y[100000], xp[100000], yp[100000], s[100000], sp[
	    100000];
} data_;

#define data_1 data_

struct {
    doublereal txa[300], tya[300], tsa[300];
} tune_;

#define tune_1 tune_

struct {
    doublecomplex zxpes[300], zypes[300], zspes[300];
} fcoe_;

#define fcoe_1 fcoe_

struct {
    doublereal dtpx[100], dtfx[100], dttx[100];
} dt_;

#define dt_1 dt_

/* Table of constant values */

static integer c__1 = 1;
static integer c__2 = 2;
static integer c__3 = 3;
static integer c__5 = 5;
static integer c__9 = 9;
static integer c__0 = 0;
static integer c_n2 = -2;
static integer c_n1 = -1;
static integer c_n3 = -3;
static integer c__6 = 6;

/* Parallelised version using Intel IA32 32-bit  compiler. On CERN lxplus needs: */
/*  source /afs/cern.ch/sw/IntelSoftware/linux/all-setup.csh ia32 */

/*  For the number of cores enter: setenv OMP_NUM_THREADS n */
/*  where n is from 1 (use for validation runs) to the number available. */
/*  Tests show the optimum is about 12 - probably due to i/o issues. */

/* Subroutine */ int sussix4drivenoise_(doublereal *xy, doublereal *tunexy, 
	doublereal *amplitude, doublereal *phase, doublereal *ox, doublereal *
	ax, doublereal *oy, doublereal *ay, char *path, ftnlen path_len)
{
    /* System generated locals */
    address a__1[2];
    integer i__1[2], i__2, i__3;
    doublereal d__1, d__2, d__3;
    olist o__1;
    cllist cl__1;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen), f_open(olist *), s_rsfe(
	    cilist *), e_rsfe(void), do_fio(integer *, char *, ftnlen);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
    integer s_rsli(icilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_rsli(void), f_clos(cllist *);
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsle(cilist *), e_wsle(void);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfi(icilist *), e_wsfi(void);

    /* Local variables */
    static char filename[8];
    extern /* Subroutine */ int writeric_(integer *, integer *, integer *, 
	    integer *, integer *);
    static integer i__, k, n;
    static char ch[200];
    static integer nf, ir, kr[100], lr[100], mr[100];
    static char ch1[200];
    static integer nt1, nt2;
    extern integer omp_get_thread_num__(void);
    static integer icf, ifi, ini, tid, nrc;
    static doublereal eps;
    static integer inv, iana, idam, iicf, ifin, itid, isme, narm, iinv, iouk, 
	    isix, nlst, ntot, nsus, idamx, nline, imeth, iconv;
    static doublereal etune[3];
    static integer iusme, iunit, ntwin;
    static doublereal tunex, tuney, tunez;
    static integer nturn, ntwix;
    extern /* Subroutine */ int datspe_(doublereal *, doublereal *, integer *,
	     integer *, integer *, integer *, integer *, integer *, integer *,
	     integer *, integer *, integer *), ordres_(doublereal *, integer *
	    , integer *, integer *, integer *, integer *, integer *, 
	    doublereal *, doublereal *, doublereal *, integer *, doublereal *,
	     doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *);
    static integer ntotal, istune;
    extern /* Subroutine */ int susres_(integer *, integer *, integer *, 
	    integer *), readdt3_(integer *, integer *, integer *, integer *, 
	    integer *, integer *), readdt4_(integer *, integer *, integer *, 
	    integer *, integer *, integer *), readric_(integer *, integer *, 
	    integer *, integer *), readsme_(integer *, integer *, integer *, 
	    integer *, integer *, integer *), readres_(integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *), readinv_(integer *, integer *, integer *, integer *, 
	    integer *, integer *);

    /* Fortran I/O blocks */
    static cilist io___35 = { 0, 0, 0, "(4(/))", 0 };
    static cilist io___36 = { 0, 0, 0, "(A)", 0 };
    static icilist io___39 = { 0, ch1, 0, 0, 200, 1 };
    static cilist io___40 = { 0, 0, 0, "(A)", 0 };
    static icilist io___41 = { 0, ch1, 0, 0, 200, 1 };
    static cilist io___42 = { 0, 0, 0, "(A)", 0 };
    static icilist io___43 = { 0, ch1, 0, 0, 200, 1 };
    static cilist io___44 = { 0, 0, 0, "(A)", 0 };
    static icilist io___45 = { 0, ch1, 0, 0, 200, 1 };
    static cilist io___46 = { 0, 0, 0, "(A)", 0 };
    static icilist io___47 = { 0, ch1, 0, 0, 200, 1 };
    static cilist io___48 = { 0, 0, 0, "(A)", 0 };
    static icilist io___49 = { 0, ch1, 0, 0, 200, 1 };
    static cilist io___50 = { 0, 0, 0, "(A)", 0 };
    static icilist io___51 = { 0, ch1, 0, 0, 200, 1 };
    static cilist io___52 = { 0, 0, 0, "(A)", 0 };
    static icilist io___53 = { 0, ch1, 0, 0, 200, 1 };
    static cilist io___54 = { 0, 0, 0, "(A)", 0 };
    static icilist io___55 = { 0, ch1, 0, 0, 200, 1 };
    static cilist io___56 = { 0, 0, 0, "(A)", 0 };
    static icilist io___57 = { 0, ch1, 0, 0, 200, 1 };
    static cilist io___58 = { 0, 0, 0, "(A)", 0 };
    static icilist io___59 = { 0, ch1, 0, 0, 200, 1 };
    static cilist io___60 = { 0, 0, 0, "(A)", 0 };
    static icilist io___61 = { 0, ch1, 0, 0, 200, 1 };
    static cilist io___62 = { 0, 0, 0, "(A)", 0 };
    static icilist io___63 = { 0, ch1, 0, 0, 200, 1 };
    static cilist io___64 = { 0, 0, 0, "(A)", 0 };
    static icilist io___65 = { 0, ch1, 0, 0, 200, 1 };
    static cilist io___66 = { 0, 0, 0, "(A)", 0 };
    static icilist io___67 = { 0, ch1, 0, 0, 200, 1 };
    static cilist io___68 = { 0, 0, 0, "(A)", 0 };
    static icilist io___69 = { 0, ch1, 0, 0, 200, 1 };
    static cilist io___71 = { 0, 0, 0, "(A)", 0 };
    static icilist io___72 = { 0, ch1, 0, 0, 200, 1 };
    static cilist io___73 = { 0, 0, 0, "(A)", 0 };
    static icilist io___74 = { 0, ch1, 0, 0, 200, 1 };
    static cilist io___75 = { 0, 0, 0, "(A)", 0 };
    static icilist io___76 = { 0, ch1, 0, 0, 200, 1 };
    static cilist io___77 = { 0, 0, 0, "(A)", 0 };
    static icilist io___78 = { 0, ch1, 0, 0, 200, 1 };
    static cilist io___79 = { 0, 0, 0, "(A)", 0 };
    static icilist io___80 = { 0, ch1, 0, 0, 200, 1 };
    static cilist io___81 = { 0, 0, 0, "(A)", 0 };
    static icilist io___82 = { 0, ch1, 0, 0, 200, 1 };
    static cilist io___83 = { 0, 0, 0, "(A)", 0 };
    static icilist io___84 = { 0, ch1, 0, 0, 200, 1 };
    static cilist io___85 = { 0, 0, 0, "(A)", 0 };
    static icilist io___86 = { 0, ch1, 0, 0, 200, 1 };
    static cilist io___87 = { 0, 0, 0, "(A)", 0 };
    static icilist io___88 = { 0, ch1, 0, 0, 200, 1 };
    static cilist io___91 = { 0, 6, 0, 0, 0 };
    static icilist io___93 = { 0, filename+5, 0, "(i2.2)", 2, 1 };
    static icilist io___99 = { 0, filename+5, 0, "(i2.2)", 2, 1 };
    static icilist io___103 = { 0, filename+5, 0, "(i3.3)", 3, 1 };
    static cilist io___104 = { 0, 6, 0, 0, 0 };
    static icilist io___105 = { 0, filename+5, 0, "(i3.3)", 3, 1 };
    static icilist io___106 = { 0, filename+5, 0, "(i3.3)", 3, 1 };
    static icilist io___107 = { 0, filename+5, 0, "(i3.3)", 3, 1 };



/* Parallelised version of sussix4drivexxNoO.f of 15/05/2011 using Openmp. */
/* Has matching Drive_God_lin.c      H.Renshall & E.Maclean */

/*  xy has been critically defined of dimension 40004, x1, y1 , x2, y2 max 10000 */
/*  and 4 for the window. See matching maxturns parameter in main and datspe. */

/*      program sussixv4 */
/* ======================================================================= */

/* SUSSIX CONTAINS: */

/* ROUTINES FOR HIGH PRECISION TUNE CALCULATION: */

/*         TUNELASR (NO WINDOW) */
/*         TUNENEWT (HANNING WINDOW) */
/*         BOTH USING ZFUNR E CALCR */

/* ROUTINES FOR FREQUENCY ANALYSIS OF SIGNALS: */

/*         SPECTRUM      !SPECTRUM COMPUTATION */

/*         ORDRES        !ORDERING OF FREQUENCIES */
/*         READRES       !READING THE ORDERED FREQUENCIES */

/* ROUTINES FOR POST PROCESSING OF SIGNALS: */

/*         SUSRES        !SUBTRACTION OF NEXT TO LEADING FREQUENCIES */
/*         READSME       !SMEAR AS QUALITY FACTOR */
/*         READINV       !INVARIANT CALCULATION */
/*         READDT3       !THIRD ORDER CONJUGATING FUNCTION COEFFICIENTS */
/*         READDT4       !FOURTH ORDER CONJUGATING FUNCTION COEFFICIENTS */

/* ROUTINES INTERFACE WITH SIXTRACK OUTPUT */

/*         READRIC       !READS SIXTRACK TRACKING OUTPUT */
/*         WRITERIC      !WRITES POSTPROCESSED DATA IN SIXTRACK OUTPUT */
/*                        FORMAT */

/* AUTHOR: R.BARTOLINI CERN AND BOLOGNA UNIVERSITY */
/* LAST MODIFIED:08/10/1997 */

/* ======================================================================= */

/*  MAIN PROGRAM FOR THE SPECTRAL ANALYSIS OF TRACKING OR BEAM DATA */

/*  TWO TYPES OF DATA MAY BE ANALYSED ACCORDING TO THE ISIX OPTION: */

/*  ISIX=0 ---> TRACKING DATA FROM A USER PROVIDED ASCII FILE */
/*  ISIX=1 ---> SIXTRACK BINARY OUTPUT, */

/*  IF ISIX=1 IT TRANSFORMS THE SIXTRACK BINARY OUTPUT INTO AN ASCII */
/*  FILE (SUBROUTINE READRIC), */

/*  MORE THAN ONE FILE CAN BE TREATED: */
/*  NTOT IS THE TOTAL NUMBER OF FILES TO BE PROCESSED */
/*  THE ASCII DATA FILES MUST START WITH FORT.90 IN DESCENDING ORDER */
/*  AND IT MUST HAVE TWO COLUMNS FOR EACH PLANE!!!!!!!!!!!!!!!!!!!!! */

/*  ONCE THE DATA ARE READ THE SPECTRUM IS CALCULATED, ORDERED AND */
/*  THE OUTPUT OF ALL THE CASES IS WRITTEN IN THE FILE FORT.300 */
/*  (SUBROUTINE DATSPE ---> SUBROUTINE RSPECTRUM, ORDRES, ETC.) */

/*  DIFFERENT KIND OF POSTPROCESSING ARE AVALIABLE AN ARE SWITCHED */
/*  ON WITH THE CORRESPONDING FLAG, BY READING THE FORT.300 WITH */
/*  THE SUBROUTINE  READRES. */
/*  NSUS GE 1 ---> SUBTRACTS THE NEXT TO LEADING FREQUENCIES */
/*  (SUBROUTINE SUSRES). IN THIS CASE THE PROGRAM ALSO WRITES THE MODIFIED */
/*  DATA BACK INTO THE STARTING SIXTRACK BYNARY OUTPUT */
/*  (SUBROUTINE WRITERIC). WARNING: IT OVERWRITES THE FILES. */
/*  ISME=1 ---> SMEAR CALCULATION */
/*  (SUBROUTINE READSME) */
/*  INV=1 ---> INVARIANT CALCULATION */
/*  (SUBROUTINE READINV) */

/*  N.B.: IF THE OUTPUT IN FORT.300 IS ALREADY AVALIABLE THE OPTION */
/*  IANA=0 ALLOWS TO SKIP DATA ANALYSIS, STARTING DIRECTLY WITH THE */
/*  FORT.300 ANALYSIS. */

/*  DESCRIPTION OF ALL INPUT ITEMS: */

/*  ISIX FLAG FOR SIXTRACK (1) OR ASCII (0) DATA */
/*  NTOT TOTAL NUMBER OF DATA FILES TO BE ANALYZED */
/*  IANA FLAG FOR FULL ANALYSIS OF DATA */
/*  ICONV IS THE FLAG FOR LINEAR TRASFORMATION (YES=1) */
/*  NT1,NT2 initial & final turn number */
/*  NARM THE MUNBER OF HARMONIC TO BE CALCULATED */
/*  ISTUNE IS THE FLAG FOR FUNDAMENTALFREQUENCIES */
/*  ISTUNE=0 => off */
/*  ISTUNE=1 uses Qx,y,z values as guess values */
/*  ISTUNE=2 takes the Qx,y,z values as fundamental frequencies */
/*  etune(3) allowed distance to Qx,y,z */
/*  TUNEX,TUNEY,TUNEZ guess or fundamental tunes */
/*  NSUS THE NUMBER OF HARMONIC TO BE SUBTRACTED */
/*  IDAM IS THE DIMENSION OF PHASE SPACE */
/*  NTWIX IS A FLAG FOR THE TWIN PARTICLES (1 or 2) */
/*  IR IS A FLAG FOR REAL SIGNAL (YES=1) */
/*  IMETH IS A FLAG FOR WINDOWING (HANNING=1, NO FILTER=0) */
/*  NRC IS THE MAXIMUM ORDER OF LINEAR COMBINATION OF FREQUENCIES */
/*  EPS IS THE TOLERANCE ON THE IDENTIFICATION OF FREQUENCIES */
/*  NLINE IS THE NUMBER OF LINES TO BE LOOKED FOR */
/*  LR MR KR SPECIFY THE LINE */
/*  IDAMX SELECT THE PLANE TO ANALYZE */
/*  IFIN IS THE UNIT FOR THE FINAL OUTPUT */
/*  ISME FLAG FOR SMEAR CALCULATION */
/*  IUSME UNIT FOR SMEAR OUTPUT */
/*  INV FLAG FOR INVARIANTS CALCULATION */
/*  IINV UNIT FOR INVARIANTS OUTPUT */
/*  ICF FLAG FOR INVARIANTS CALCULATION */
/*  IICF UNIT FOR INVARIANTS OUTPUT */

/*  THE SPECTRUM IS WRITTEN IN THE UNIT 300 */

/*  AUTHORS: R.BARTOLINI & F.SCHMIDT */
/*  MODIFIED 16/09/1996: ADDED THE ICONV OPTION */
/*  MODIFIED 17/09/1996: ADDED THE INPUT FROM FILE */
/*  MODIFIED 20/08/1997: ADDED THE INVARIANT CALCULATION */
/*  MODIFIED 17/09/1997: ADDED THE TREATEMENT OF ASCII BEAM DATA */
/*  MODIFIED 30/05/1998: ADDED DEFAULT VALUES, AND FFT */
/*  MODIFIED 12/10/1999: TOTAL CLEAN-UP */

/* $OMP THREADPRIVATE(tid,itid, */
/* $OMP&i,iana,icf,iconv,idam,idamx,ifi,ifin,iicf,iinv,imeth,ini, */
/* $OMP&inv,iouk,ir,isix,isme,istune,iunit,iusme,k,kr,lr,mr,n,narm, */
/* $OMP&nf,nline,nlst,nrc,nsus,nt1,nt2,ntot,ntotal,nturn,ntwin,ntwix, */
/* $OMP&eps,etune,tunex,tuney,tunez, */
/* $OMP&ch,ch1,filename) */
/* =================== */
/* .....INIZIALIZATION */
/* =================== */
/* HRR      call omp_set_dynamic(.false.) */
/* ========================= */
/* .....DEFAULT VALUES FIRST */
/* ========================= */
    /* Parameter adjustments */
    --ay;
    --oy;
    --ax;
    --ox;
    --phase;
    --amplitude;
    --tunexy;
    --xy;

    /* Function Body */
    isix = 1;
    ntot = 1;
    iana = 1;
    iconv = 1;
    nt1 = 1;
    nt2 = 1024;
    narm = 1;
    istune = 0;
    etune[0] = .01;
    etune[1] = .01;
    etune[2] = .01;
    tunex = .28f;
    tuney = .31f;
    tunez = .006f;
    nsus = 0;
    idam = 2;
    ntwix = 1;
    ir = 0;
    imeth = 2;
    nrc = 10;
    eps = 1e-6;
    nline = 1;
    for (i__ = 1; i__ <= 100; ++i__) {
	lr[i__ - 1] = 0;
	mr[i__ - 1] = 0;
	kr[i__ - 1] = 0;
/* L1: */
    }
    lr[0] = 1;
    idamx = 1;
    ifin = 500;
    isme = 0;
    iusme = 200;
    inv = 0;
    iinv = 250;
    icf = 0;
    iicf = 350;
/* ========================= */
/* .....READS THE INPUT FILE */
/* ========================= */
/*     write(*,*)"Here comes the input file" */
    i__ = i_indx(path, "sussix_v4.inp", (ftnlen)4000, (ftnlen)13);
/*     write(*,*) path(1:i+12), i */
    tid = omp_get_thread_num__();
/*     write(*,*) tid */
    itid = tid + 10;
/* $OMP CRITICAL */
    o__1.oerr = 0;
    o__1.ounit = itid;
    o__1.ofnmlen = i__ + 12;
    o__1.ofnm = path;
    o__1.orl = 0;
    o__1.osta = "unknown";
    o__1.oacc = 0;
    o__1.ofm = "formatted";
    o__1.oblnk = 0;
    f_open(&o__1);
    io___35.ciunit = itid;
    s_rsfe(&io___35);
    e_rsfe();
    io___36.ciunit = itid;
    s_rsfe(&io___36);
    do_fio(&c__1, ch, (ftnlen)200);
    e_rsfe();
/* Writing concatenation */
    i__1[0] = 72, a__1[0] = ch + 8;
    i__1[1] = 3, a__1[1] = " / ";
    s_cat(ch1, a__1, i__1, &c__2, (ftnlen)200);
    s_rsli(&io___39);
    do_lio(&c__3, &c__1, (char *)&isix, (ftnlen)sizeof(integer));
    e_rsli();
    io___40.ciunit = itid;
    s_rsfe(&io___40);
    do_fio(&c__1, ch, (ftnlen)200);
    e_rsfe();
/* Writing concatenation */
    i__1[0] = 72, a__1[0] = ch + 8;
    i__1[1] = 3, a__1[1] = " / ";
    s_cat(ch1, a__1, i__1, &c__2, (ftnlen)200);
    s_rsli(&io___41);
    do_lio(&c__3, &c__1, (char *)&ntot, (ftnlen)sizeof(integer));
    e_rsli();
/*     write(*,*)"ntot=",ntot */
    io___42.ciunit = itid;
    s_rsfe(&io___42);
    do_fio(&c__1, ch, (ftnlen)200);
    e_rsfe();
/* Writing concatenation */
    i__1[0] = 72, a__1[0] = ch + 8;
    i__1[1] = 3, a__1[1] = " / ";
    s_cat(ch1, a__1, i__1, &c__2, (ftnlen)200);
    s_rsli(&io___43);
    do_lio(&c__3, &c__1, (char *)&iana, (ftnlen)sizeof(integer));
    e_rsli();
    io___44.ciunit = itid;
    s_rsfe(&io___44);
    do_fio(&c__1, ch, (ftnlen)200);
    e_rsfe();
/* Writing concatenation */
    i__1[0] = 72, a__1[0] = ch + 8;
    i__1[1] = 3, a__1[1] = " / ";
    s_cat(ch1, a__1, i__1, &c__2, (ftnlen)200);
    s_rsli(&io___45);
    do_lio(&c__3, &c__1, (char *)&iconv, (ftnlen)sizeof(integer));
    e_rsli();
    io___46.ciunit = itid;
    s_rsfe(&io___46);
    do_fio(&c__1, ch, (ftnlen)200);
    e_rsfe();
/* Writing concatenation */
    i__1[0] = 72, a__1[0] = ch + 8;
    i__1[1] = 3, a__1[1] = " / ";
    s_cat(ch1, a__1, i__1, &c__2, (ftnlen)200);
    s_rsli(&io___47);
    do_lio(&c__3, &c__1, (char *)&nt1, (ftnlen)sizeof(integer));
    do_lio(&c__3, &c__1, (char *)&nt2, (ftnlen)sizeof(integer));
    e_rsli();
    io___48.ciunit = itid;
    s_rsfe(&io___48);
    do_fio(&c__1, ch, (ftnlen)200);
    e_rsfe();
/* Writing concatenation */
    i__1[0] = 72, a__1[0] = ch + 8;
    i__1[1] = 3, a__1[1] = " / ";
    s_cat(ch1, a__1, i__1, &c__2, (ftnlen)200);
    s_rsli(&io___49);
    do_lio(&c__3, &c__1, (char *)&narm, (ftnlen)sizeof(integer));
    e_rsli();
    io___50.ciunit = itid;
    s_rsfe(&io___50);
    do_fio(&c__1, ch, (ftnlen)200);
    e_rsfe();
/* Writing concatenation */
    i__1[0] = 72, a__1[0] = ch + 8;
    i__1[1] = 3, a__1[1] = " / ";
    s_cat(ch1, a__1, i__1, &c__2, (ftnlen)200);
    s_rsli(&io___51);
    do_lio(&c__3, &c__1, (char *)&istune, (ftnlen)sizeof(integer));
    do_lio(&c__5, &c__1, (char *)&etune[0], (ftnlen)sizeof(doublereal));
    do_lio(&c__5, &c__1, (char *)&etune[1], (ftnlen)sizeof(doublereal));
    do_lio(&c__5, &c__1, (char *)&etune[2], (ftnlen)sizeof(doublereal));
    e_rsli();
    io___52.ciunit = itid;
    s_rsfe(&io___52);
    do_fio(&c__1, ch, (ftnlen)200);
    e_rsfe();
/* Writing concatenation */
    i__1[0] = 72, a__1[0] = ch + 8;
    i__1[1] = 3, a__1[1] = " / ";
    s_cat(ch1, a__1, i__1, &c__2, (ftnlen)200);
    s_rsli(&io___53);
    do_lio(&c__5, &c__1, (char *)&tunex, (ftnlen)sizeof(doublereal));
    do_lio(&c__5, &c__1, (char *)&tuney, (ftnlen)sizeof(doublereal));
    do_lio(&c__5, &c__1, (char *)&tunez, (ftnlen)sizeof(doublereal));
    e_rsli();
    io___54.ciunit = itid;
    s_rsfe(&io___54);
    do_fio(&c__1, ch, (ftnlen)200);
    e_rsfe();
/* Writing concatenation */
    i__1[0] = 72, a__1[0] = ch + 8;
    i__1[1] = 3, a__1[1] = " / ";
    s_cat(ch1, a__1, i__1, &c__2, (ftnlen)200);
    s_rsli(&io___55);
    do_lio(&c__3, &c__1, (char *)&nsus, (ftnlen)sizeof(integer));
    e_rsli();
    io___56.ciunit = itid;
    s_rsfe(&io___56);
    do_fio(&c__1, ch, (ftnlen)200);
    e_rsfe();
/* Writing concatenation */
    i__1[0] = 72, a__1[0] = ch + 8;
    i__1[1] = 3, a__1[1] = " / ";
    s_cat(ch1, a__1, i__1, &c__2, (ftnlen)200);
    s_rsli(&io___57);
    do_lio(&c__3, &c__1, (char *)&idam, (ftnlen)sizeof(integer));
    e_rsli();
    io___58.ciunit = itid;
    s_rsfe(&io___58);
    do_fio(&c__1, ch, (ftnlen)200);
    e_rsfe();
/* Writing concatenation */
    i__1[0] = 72, a__1[0] = ch + 8;
    i__1[1] = 3, a__1[1] = " / ";
    s_cat(ch1, a__1, i__1, &c__2, (ftnlen)200);
    s_rsli(&io___59);
    do_lio(&c__3, &c__1, (char *)&ntwix, (ftnlen)sizeof(integer));
    e_rsli();
    io___60.ciunit = itid;
    s_rsfe(&io___60);
    do_fio(&c__1, ch, (ftnlen)200);
    e_rsfe();
/* Writing concatenation */
    i__1[0] = 72, a__1[0] = ch + 8;
    i__1[1] = 3, a__1[1] = " / ";
    s_cat(ch1, a__1, i__1, &c__2, (ftnlen)200);
    s_rsli(&io___61);
    do_lio(&c__3, &c__1, (char *)&ir, (ftnlen)sizeof(integer));
    e_rsli();
    io___62.ciunit = itid;
    s_rsfe(&io___62);
    do_fio(&c__1, ch, (ftnlen)200);
    e_rsfe();
/* Writing concatenation */
    i__1[0] = 72, a__1[0] = ch + 8;
    i__1[1] = 3, a__1[1] = " / ";
    s_cat(ch1, a__1, i__1, &c__2, (ftnlen)200);
    s_rsli(&io___63);
    do_lio(&c__3, &c__1, (char *)&imeth, (ftnlen)sizeof(integer));
    e_rsli();
    io___64.ciunit = itid;
    s_rsfe(&io___64);
    do_fio(&c__1, ch, (ftnlen)200);
    e_rsfe();
/* Writing concatenation */
    i__1[0] = 72, a__1[0] = ch + 8;
    i__1[1] = 3, a__1[1] = " / ";
    s_cat(ch1, a__1, i__1, &c__2, (ftnlen)200);
    s_rsli(&io___65);
    do_lio(&c__3, &c__1, (char *)&nrc, (ftnlen)sizeof(integer));
    e_rsli();
    io___66.ciunit = itid;
    s_rsfe(&io___66);
    do_fio(&c__1, ch, (ftnlen)200);
    e_rsfe();
/* Writing concatenation */
    i__1[0] = 72, a__1[0] = ch + 8;
    i__1[1] = 3, a__1[1] = " / ";
    s_cat(ch1, a__1, i__1, &c__2, (ftnlen)200);
    s_rsli(&io___67);
    do_lio(&c__5, &c__1, (char *)&eps, (ftnlen)sizeof(doublereal));
    e_rsli();
    io___68.ciunit = itid;
    s_rsfe(&io___68);
    do_fio(&c__1, ch, (ftnlen)200);
    e_rsfe();
/* Writing concatenation */
    i__1[0] = 72, a__1[0] = ch + 8;
    i__1[1] = 3, a__1[1] = " / ";
    s_cat(ch1, a__1, i__1, &c__2, (ftnlen)200);
    s_rsli(&io___69);
    do_lio(&c__3, &c__1, (char *)&nline, (ftnlen)sizeof(integer));
    e_rsli();
    i__2 = nline;
    for (k = 1; k <= i__2; ++k) {
	io___71.ciunit = itid;
	s_rsfe(&io___71);
	do_fio(&c__1, ch, (ftnlen)200);
	e_rsfe();
/* Writing concatenation */
	i__1[0] = 72, a__1[0] = ch + 8;
	i__1[1] = 3, a__1[1] = " / ";
	s_cat(ch1, a__1, i__1, &c__2, (ftnlen)200);
	s_rsli(&io___72);
	do_lio(&c__3, &c__1, (char *)&lr[k - 1], (ftnlen)sizeof(integer));
	do_lio(&c__3, &c__1, (char *)&mr[k - 1], (ftnlen)sizeof(integer));
	do_lio(&c__3, &c__1, (char *)&kr[k - 1], (ftnlen)sizeof(integer));
	e_rsli();
/* HRR        write (6,*)"k,lr,mr,kr",k,lr(k),mr(k),kr(k) */
    }
    io___73.ciunit = itid;
    s_rsfe(&io___73);
    do_fio(&c__1, ch, (ftnlen)200);
    e_rsfe();
/* Writing concatenation */
    i__1[0] = 72, a__1[0] = ch + 8;
    i__1[1] = 3, a__1[1] = " / ";
    s_cat(ch1, a__1, i__1, &c__2, (ftnlen)200);
    s_rsli(&io___74);
    do_lio(&c__3, &c__1, (char *)&idamx, (ftnlen)sizeof(integer));
    e_rsli();
    io___75.ciunit = itid;
    s_rsfe(&io___75);
    do_fio(&c__1, ch, (ftnlen)200);
    e_rsfe();
/* Writing concatenation */
    i__1[0] = 72, a__1[0] = ch + 8;
    i__1[1] = 3, a__1[1] = " / ";
    s_cat(ch1, a__1, i__1, &c__2, (ftnlen)200);
    s_rsli(&io___76);
    do_lio(&c__3, &c__1, (char *)&ifin, (ftnlen)sizeof(integer));
    e_rsli();
    io___77.ciunit = itid;
    s_rsfe(&io___77);
    do_fio(&c__1, ch, (ftnlen)200);
    e_rsfe();
/* Writing concatenation */
    i__1[0] = 72, a__1[0] = ch + 8;
    i__1[1] = 3, a__1[1] = " / ";
    s_cat(ch1, a__1, i__1, &c__2, (ftnlen)200);
    s_rsli(&io___78);
    do_lio(&c__3, &c__1, (char *)&isme, (ftnlen)sizeof(integer));
    e_rsli();
/* HRR      write (6,*)"ISME",isme */
    io___79.ciunit = itid;
    s_rsfe(&io___79);
    do_fio(&c__1, ch, (ftnlen)200);
    e_rsfe();
/* Writing concatenation */
    i__1[0] = 72, a__1[0] = ch + 8;
    i__1[1] = 3, a__1[1] = " / ";
    s_cat(ch1, a__1, i__1, &c__2, (ftnlen)200);
    s_rsli(&io___80);
    do_lio(&c__3, &c__1, (char *)&iusme, (ftnlen)sizeof(integer));
    e_rsli();
    io___81.ciunit = itid;
    s_rsfe(&io___81);
    do_fio(&c__1, ch, (ftnlen)200);
    e_rsfe();
/* Writing concatenation */
    i__1[0] = 72, a__1[0] = ch + 8;
    i__1[1] = 3, a__1[1] = " / ";
    s_cat(ch1, a__1, i__1, &c__2, (ftnlen)200);
    s_rsli(&io___82);
    do_lio(&c__3, &c__1, (char *)&inv, (ftnlen)sizeof(integer));
    e_rsli();
    io___83.ciunit = itid;
    s_rsfe(&io___83);
    do_fio(&c__1, ch, (ftnlen)200);
    e_rsfe();
/* Writing concatenation */
    i__1[0] = 72, a__1[0] = ch + 8;
    i__1[1] = 3, a__1[1] = " / ";
    s_cat(ch1, a__1, i__1, &c__2, (ftnlen)200);
    s_rsli(&io___84);
    do_lio(&c__3, &c__1, (char *)&iinv, (ftnlen)sizeof(integer));
    e_rsli();
    io___85.ciunit = itid;
    s_rsfe(&io___85);
    do_fio(&c__1, ch, (ftnlen)200);
    e_rsfe();
/* Writing concatenation */
    i__1[0] = 72, a__1[0] = ch + 8;
    i__1[1] = 3, a__1[1] = " / ";
    s_cat(ch1, a__1, i__1, &c__2, (ftnlen)200);
    s_rsli(&io___86);
    do_lio(&c__3, &c__1, (char *)&icf, (ftnlen)sizeof(integer));
    e_rsli();
    io___87.ciunit = itid;
    s_rsfe(&io___87);
    do_fio(&c__1, ch, (ftnlen)200);
    e_rsfe();
/* Writing concatenation */
    i__1[0] = 72, a__1[0] = ch + 8;
    i__1[1] = 3, a__1[1] = " / ";
    s_cat(ch1, a__1, i__1, &c__2, (ftnlen)200);
    s_rsli(&io___88);
    do_lio(&c__3, &c__1, (char *)&iicf, (ftnlen)sizeof(integer));
    e_rsli();
    cl__1.cerr = 0;
    cl__1.cunit = itid;
    cl__1.csta = 0;
    f_clos(&cl__1);
/* $OMP END CRITICAL */
/* .....CHECKS */
    if (narm <= 0) {
/*        write(6,*) 'NARM too small' */
	cl__1.cerr = 0;
	cl__1.cunit = itid;
	cl__1.csta = 0;
	f_clos(&cl__1);
	s_stop("", (ftnlen)0);
    }
    if (narm > 300) {
/*        write(6,*) 'NARM too big => reduced to maximum: ',mterm */
	narm = 300;
    }
    if (nt1 <= 0) {
/*        write(6,*) 'NT1 too small' */
	cl__1.cerr = 0;
	cl__1.cunit = itid;
	cl__1.csta = 0;
	f_clos(&cl__1);
	s_stop("", (ftnlen)0);
    }
    if (nt2 <= nt1) {
/*        write(6,*) 'NT2 smaller than NT1' */
	cl__1.cerr = 0;
	cl__1.cunit = itid;
	cl__1.csta = 0;
	f_clos(&cl__1);
	s_stop("", (ftnlen)0);
    }
    if (idam != 1 && idam != 2 && idam != 3) {
/*        write(6,*) 'The order of phase space IDAM must be 1, 2 or 3' */
	cl__1.cerr = 0;
	cl__1.cunit = itid;
	cl__1.csta = 0;
	f_clos(&cl__1);
	s_stop("", (ftnlen)0);
    }
    if (ntot > 32) {
/*        write(6,*) 'NTOT too big => reduced to maximum: ',32 */
	ntot = 32;
    }
    if (ntwix != 1 && ntwix != 2) {
/*        write(6,*) 'NTWIX ill defined, set to: ',1 */
	ntwix = 1;
    }
/* ============================== */
/* .....END OF THE INIZIALIZATION */
/* ============================== */
/* =========================== */
/* .....STARTING DATA ANALYSIS */
/* =========================== */
/* .....1) CHECK IF THE FORT.300 IS ALREADY PRODUCED */
/* .....IF NOT (IANA=1 or 2) */
/* ........2) CHECK THE ISIX OPTION */
/* ........3) PROCEED WITH SPECTRUM CALCULATION */
/* ........4) FFT IF IANA=2 */
/* .....IF YES (IANA=0) */
/* ........2) PROCEED WITH POSTPROCESSING */
/*      open(30,file='fort.300',form='formatted',status='unknown') */
    if (iana == 1 || iana == 2) {
	if (isix == 1) {
/* @@@@@@@@@@@@@@@@@@@@@@ */
/* .....SIXTRACK DATA   @ */
/* @@@@@@@@@@@@@@@@@@@@@@ */
/* $OMP CRITICAL */
	    nlst = 90 - ntot + 1;
	    o__1.oerr = 0;
	    o__1.ounit = 91;
	    o__1.ofnmlen = 7;
	    o__1.ofnm = "fort.91";
	    o__1.orl = 0;
	    o__1.osta = "unknown";
	    o__1.oacc = 0;
	    o__1.ofm = "formatted";
	    o__1.oblnk = 0;
	    f_open(&o__1);
	    o__1.oerr = 0;
	    o__1.ounit = 92;
	    o__1.ofnmlen = 7;
	    o__1.ofnm = "fort.92";
	    o__1.orl = 0;
	    o__1.osta = "unknown";
	    o__1.oacc = 0;
	    o__1.ofm = "formatted";
	    o__1.oblnk = 0;
	    f_open(&o__1);
	    i__2 = nlst;
	    for (n = 90; n >= i__2; --n) {
		if (n > 58) {
		    goto L100;
		}
		s_wsle(&io___91);
		do_lio(&c__9, &c__1, "Unit for sixtrack input must be above "
			"58", (ftnlen)40);
		e_wsle();
		s_stop("", (ftnlen)0);
L100:
		s_copy(filename, "fort.", (ftnlen)8, (ftnlen)5);
		s_wsfi(&io___93);
		do_fio(&c__1, (char *)&n, (ftnlen)sizeof(integer));
		e_wsfi();
		o__1.oerr = 0;
		o__1.ounit = n;
		o__1.ofnmlen = 8;
		o__1.ofnm = filename;
		o__1.orl = 0;
		o__1.osta = "unknown";
		o__1.oacc = 0;
		o__1.ofm = "unformatted";
		o__1.oblnk = 0;
		f_open(&o__1);
		readric_(&n, &idam, &ntwin, &iconv);
/* .....NOW READRIC HAS CREATED NTWIN ASCII FILES IN UNIT 91 AND */
/* .....EVENTUALLY 92. NTWIN IS AN OUTPUT PARAMETER OF READRIC!! */
		if (ntwix < ntwin) {
/*              write(6,*)'WARNING: THE TWIN PARTICLE IS IGNORED' */
		    if (nsus >= 2) {
/*                write(6,*)'ERROR: TWIN PARTICLE NEEDED' */
			cl__1.cerr = 0;
			cl__1.cunit = 10;
			cl__1.csta = 0;
			f_clos(&cl__1);
/*                close(30) */
			s_stop("", (ftnlen)0);
		    }
		}
		i__3 = ntwix;
		for (nf = 1; nf <= i__3; ++nf) {
		    iunit = nf + 90;
		    datspe_(&xy[1], &eps, &iunit, &idam, &ir, &nt1, &nt2, &
			    nturn, &imeth, &narm, &nrc, &iana);
/* .....N.B. NTURN IS AN OUTPUT PARAMETER OF DATSPE */
		    d__1 = -tunex;
		    d__2 = -tuney;
		    d__3 = -tunez;
		    ordres_(&eps, &narm, &nrc, &ir, &idam, &iunit, &nturn, &
			    d__1, &d__2, &d__3, &istune, etune, &tunexy[1], &
			    amplitude[1], &phase[1], &ox[1], &ax[1], &oy[1], &
			    ay[1]);
		    if (nsus >= 2) {
/* .....SUBTRACTS AND OVERWRITE UNIT IUNIT */
			susres_(&iunit, &nsus, &nturn, &c__3);
		    }
		}
		if (nsus >= 2) {
/* .....N.B. WRITERIC NEEDS BOTH THE FILES TREATED WITH SUSRES */
/* .....     IT OVERWRITES THE INITIAL SIXTRACK OUTPUT!!!!!!!! */
		    writeric_(&n, &ntotal, &ntwin, &nturn, &iconv);
		}
	    }
/* $OMP END CRITICAL */
	} else if (isix == 0) {
/* @@@@@@@@@@@@@@@@@@@@ */
/* ......ASCII DATA   @ */
/* @@@@@@@@@@@@@@@@@@@@ */
	    i__2 = ntot;
	    for (n = 1; n <= i__2; ++n) {
		iunit = 91 - n;
		s_copy(filename, "fort.", (ftnlen)8, (ftnlen)5);
		s_wsfi(&io___99);
		do_fio(&c__1, (char *)&iunit, (ftnlen)sizeof(integer));
		e_wsfi();
/*            open(iunit,file=filename,form='formatted',status='unknown') */
		datspe_(&xy[1], &eps, &iunit, &idam, &ir, &nt1, &nt2, &nturn, 
			&imeth, &narm, &nrc, &iana);
		d__1 = -tunex;
		d__2 = -tuney;
		d__3 = -tunez;
		ordres_(&eps, &narm, &nrc, &ir, &idam, &iunit, &nturn, &d__1, 
			&d__2, &d__3, &istune, etune, &tunexy[1], &amplitude[
			1], &phase[1], &ox[1], &ax[1], &oy[1], &ay[1]);
/*            close(iunit) */
	    }
	}
    }
    cl__1.cerr = 0;
    cl__1.cunit = 91;
    cl__1.csta = 0;
    f_clos(&cl__1);
    cl__1.cerr = 0;
    cl__1.cunit = 92;
    cl__1.csta = 0;
    f_clos(&cl__1);
/* ============================================= */
/* .....STARTING POSTPROCESSING OF ANALYZED DATA */
/* ============================================= */
/* ......1) SELECTION OF LINES */
/* ......2) SMEAR CALCULATION */
/* ......3) INVARIANT CALCULATION */
    if (isix == 1) {
/* .......NTOT*NTWIX CASES ANALYZED FROM FORT.300 */
	ini = 90;
	ifi = ini - ntot * ntwix + 1;
    } else if (isix == 0) {
/* .......NTOT CASES ANALYZED FROM FORT.300 */
	ini = 90;
	ifi = ini - ntot + 1;
    }
/*      write(6,*)' ' */
/*      write(6,*)'*************************************** ' */
/*      write(6,*)'STARTING THE FORT.300 ANALYSIS OF CASES:',ini,ifi */
/*      write(6,*)'*************************************** ' */
/* .....SELECTION OF NLINE LINES SPECIFIED IN THE ARRAY LR,MR,KR */
/* .....THE RESULTS ARE WRITTEN IN THE UNIT IOUK, IDAMX IS THE */
/* .....PLANE TO BE ANALYZED */
    i__2 = nline;
    for (k = 1; k <= i__2; ++k) {
	iouk = ifin + k;
	if (iouk > 999) {
/*          write(6,*) 'Unit for resonance output  must be below 1000' */
	    cl__1.cerr = 0;
	    cl__1.cunit = 10;
	    cl__1.csta = 0;
	    f_clos(&cl__1);
/*          close(30) */
	    s_stop("", (ftnlen)0);
	}
	s_copy(filename, "fort.", (ftnlen)8, (ftnlen)5);
	s_wsfi(&io___103);
	do_fio(&c__1, (char *)&iouk, (ftnlen)sizeof(integer));
	e_wsfi();
	o__1.oerr = 0;
	o__1.ounit = iouk;
	o__1.ofnmlen = 8;
	o__1.ofnm = filename;
	o__1.orl = 0;
	o__1.osta = "unknown";
	o__1.oacc = 0;
	o__1.ofm = "formatted";
	o__1.oblnk = 0;
	f_open(&o__1);
	readres_(&ini, &ifi, &lr[k - 1], &mr[k - 1], &kr[k - 1], &narm, &idam,
		 &idamx, &iouk);
	cl__1.cerr = 0;
	cl__1.cunit = iouk;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
/* .....SMEAR CALCULATION: OUTPUT IN THE UNIT IUSME */
    if (isme == 1) {
	s_wsle(&io___104);
	do_lio(&c__9, &c__1, "SMEAR CALCULATION: OUTPUT IN THE UNIT", (ftnlen)
		37);
	do_lio(&c__3, &c__1, (char *)&iusme, (ftnlen)sizeof(integer));
	e_wsle();
	if (iusme > 999) {
/*          write(6,*) 'Unit for smear calculation must be below 1000' */
	    cl__1.cerr = 0;
	    cl__1.cunit = 10;
	    cl__1.csta = 0;
	    f_clos(&cl__1);
/*          close(30) */
	    s_stop("", (ftnlen)0);
	}
	s_copy(filename, "fort.", (ftnlen)8, (ftnlen)5);
	s_wsfi(&io___105);
	do_fio(&c__1, (char *)&iusme, (ftnlen)sizeof(integer));
	e_wsfi();
	o__1.oerr = 0;
	o__1.ounit = iusme;
	o__1.ofnmlen = 8;
	o__1.ofnm = filename;
	o__1.orl = 0;
	o__1.osta = "unknown";
	o__1.oacc = 0;
	o__1.ofm = "formatted";
	o__1.oblnk = 0;
	f_open(&o__1);
	readsme_(&ini, &ifi, &narm, &idam, &idamx, &iusme);
	cl__1.cerr = 0;
	cl__1.cunit = iusme;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
/* .....INVARIANT CALCULATION: OUTPUT IN THE UNIT IINV */
    if (inv == 1) {
	if (iinv > 999) {
/*          write(6,*) 'Unit for invariant calculation must be below 1000' */
	    cl__1.cerr = 0;
	    cl__1.cunit = 10;
	    cl__1.csta = 0;
	    f_clos(&cl__1);
/*          close(30) */
	    s_stop("", (ftnlen)0);
	}
	s_copy(filename, "fort.", (ftnlen)8, (ftnlen)5);
	s_wsfi(&io___106);
	do_fio(&c__1, (char *)&iinv, (ftnlen)sizeof(integer));
	e_wsfi();
	o__1.oerr = 0;
	o__1.ounit = iinv;
	o__1.ofnmlen = 8;
	o__1.ofnm = filename;
	o__1.orl = 0;
	o__1.osta = "unknown";
	o__1.oacc = 0;
	o__1.ofm = "formatted";
	o__1.oblnk = 0;
	f_open(&o__1);
/*        write(6,*)'INVARIANT CALCULATION: OUTPUT IN THE UNIT',iinv */
	readinv_(&ini, &ifi, &narm, &idam, &idamx, &iinv);
	cl__1.cerr = 0;
	cl__1.cunit = iinv;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
/* .....3-RD ORDER CONJUGATING FUNCTION CALCULATION: OUTPUT IN THE UNIT ICF */
    if (icf == 1) {
/*        write(6,*)'3-RD ORDER CONJUG. FUNC.: OUTPUT IN THE UNIT',iicf */
	if (iicf > 999) {
/*          write(6,*) 'Unit for conjugating function must be below 1000' */
	    cl__1.cerr = 0;
	    cl__1.cunit = 10;
	    cl__1.csta = 0;
	    f_clos(&cl__1);
/*          close(30) */
	    s_stop("", (ftnlen)0);
	}
	s_copy(filename, "fort.", (ftnlen)8, (ftnlen)5);
	s_wsfi(&io___107);
	do_fio(&c__1, (char *)&iicf, (ftnlen)sizeof(integer));
	e_wsfi();
	o__1.oerr = 0;
	o__1.ounit = iicf;
	o__1.ofnmlen = 8;
	o__1.ofnm = filename;
	o__1.orl = 0;
	o__1.osta = "unknown";
	o__1.oacc = 0;
	o__1.ofm = "formatted";
	o__1.oblnk = 0;
	f_open(&o__1);
	readdt3_(&ini, &ifi, &narm, &idam, &idamx, &iicf);
	readdt4_(&ini, &ifi, &narm, &idam, &idamx, &iicf);
	cl__1.cerr = 0;
	cl__1.cunit = iicf;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
/*      close(10) */
/*      close(30) */
    return 0;
} /* sussix4drivenoise_ */

/* Subroutine */ int spectrum_(doublereal *x, doublereal *xp, integer *maxn, 
	doublereal *tune, doublecomplex *zpesi, integer *narm, integer *meth)
{
    /* System generated locals */
    integer i__1, i__2, i__3, i__4, i__5;
    doublereal d__1;
    doublecomplex z__1, z__2;
    cllist cl__1;

    /* Builtin functions */
    double atan(doublereal);
    integer f_clos(cllist *);
    /* Subroutine */ int s_stop(char *, ftnlen);
    void z_exp(doublecomplex *, doublecomplex *);
    double d_imag(doublecomplex *);

    /* Local variables */
    extern doublereal tunelasr_(doublereal *, doublereal *, integer *, 
	    doublecomplex *), tunenewt_(doublereal *, doublereal *, integer *,
	     doublecomplex *);
    static integer n;
    static doublecomplex z__[100000];
    static integer na;
    static doublereal pi;
    static doublecomplex zw, zx, zz[100000], zef, zgs[100000];
    static doublereal freq, duepi;

/* ======================================================================= */

/* SUBROUTINE SPECTRUM */

/* COMPUTE THE MAIN FREQUENCY */
/* X, XP ARE THE COORDINATES OF THE ORBIT AND MAXN IS THE */
/* LENGTH IF THE ORBIT. */
/* WITHOUT ORTHOGONALIZATION OF GRAM-SCHMIDT */

/* METH SELECTS THE WINDOW: */
/*     1 --> HANNING WINDOW */
/*     2 --> RECTANGULAR WINDOW */

/* AUTHOR:  R. BARTOLINI 9/1/1996 */
/*          A. BAZZANI */

/* ======================================================================= */
/* $OMP THREADPRIVATE(z,zz,freq,zef,zw,zx,zgs,n,na,duepi,pi) */
/* =============== */
/* INIZIALIZATION */
/* =============== */
    /* Parameter adjustments */
    --zpesi;
    --tune;
    --xp;
    --x;

    /* Function Body */
    pi = atan(1.) * 4.;
    duepi = pi * 2;
    if (*maxn > 100000) {
/*        write(6,*) 'ERROR IN SPECTRUM: MAXN TOO LARGE' */
	cl__1.cerr = 0;
	cl__1.cunit = 10;
	cl__1.csta = 0;
	f_clos(&cl__1);
/*        close(30) */
	s_stop("", (ftnlen)0);
    }
    if (*narm < 2) {
/*        write(6,*) 'ERROR IN SPECTRUM: NA SMALLER THAN 2' */
	cl__1.cerr = 0;
	cl__1.cunit = 10;
	cl__1.csta = 0;
	f_clos(&cl__1);
/*        close(30) */
	s_stop("", (ftnlen)0);
    }
    i__1 = *maxn;
    for (n = 1; n <= i__1; ++n) {
	i__2 = n - 1;
	i__3 = n;
	i__4 = n;
	z__1.r = x[i__3], z__1.i = xp[i__4];
	z__[i__2].r = z__1.r, z__[i__2].i = z__1.i;
	i__2 = n - 1;
	i__3 = n - 1;
	zz[i__2].r = z__[i__3].r, zz[i__2].i = z__[i__3].i;
    }
    i__1 = *narm;
    for (na = 1; na <= i__1; ++na) {
	if (*meth == 1) {
	    tune[na] = tunenewt_(&x[1], &xp[1], maxn, &zw);
	} else if (*meth == 2) {
	    tune[na] = tunelasr_(&x[1], &xp[1], maxn, &zw);
	}
/* .....beginning of subtraction procedure */
	freq = tune[na];
	i__2 = na;
	d__1 = (doublereal) (*maxn);
	z__1.r = zw.r / d__1, z__1.i = zw.i / d__1;
	zpesi[i__2].r = z__1.r, zpesi[i__2].i = z__1.i;
	d__1 = freq * duepi;
	z__2.r = 0., z__2.i = d__1;
	z_exp(&z__1, &z__2);
	zef.r = z__1.r, zef.i = z__1.i;
	zx.r = 1., zx.i = 0.;
	i__2 = na;
	z__1.r = zpesi[i__2].r * zx.r - zpesi[i__2].i * zx.i, z__1.i = zpesi[
		i__2].r * zx.i + zpesi[i__2].i * zx.r;
	zgs[0].r = z__1.r, zgs[0].i = z__1.i;
	i__2 = *maxn;
	for (n = 2; n <= i__2; ++n) {
	    z__1.r = zx.r * zef.r - zx.i * zef.i, z__1.i = zx.r * zef.i + 
		    zx.i * zef.r;
	    zx.r = z__1.r, zx.i = z__1.i;
	    i__3 = n - 1;
	    i__4 = na;
	    z__1.r = zpesi[i__4].r * zx.r - zpesi[i__4].i * zx.i, z__1.i = 
		    zpesi[i__4].r * zx.i + zpesi[i__4].i * zx.r;
	    zgs[i__3].r = z__1.r, zgs[i__3].i = z__1.i;
	}
	i__2 = *maxn;
	for (n = 1; n <= i__2; ++n) {
	    i__3 = n - 1;
	    i__4 = n - 1;
	    i__5 = n - 1;
	    z__1.r = z__[i__4].r - zgs[i__5].r, z__1.i = z__[i__4].i - zgs[
		    i__5].i;
	    z__[i__3].r = z__1.r, z__[i__3].i = z__1.i;
	}
	i__2 = *maxn;
	for (n = 1; n <= i__2; ++n) {
	    i__3 = n - 1;
	    x[n] = z__[i__3].r;
	    xp[n] = d_imag(&z__[n - 1]);
	}
    }
/* .....restore the original signal in x, xp. */
    i__1 = *maxn;
    for (n = 1; n <= i__1; ++n) {
	i__2 = n - 1;
	x[n] = zz[i__2].r;
	xp[n] = d_imag(&zz[n - 1]);
    }
    return 0;
} /* spectrum_ */

doublereal tunenewt_(doublereal *x, doublereal *xp, integer *maxn, 
	doublecomplex *zw)
{
    /* System generated locals */
    integer i__1, i__2, i__3, i__4;
    doublereal ret_val, d__1;
    doublecomplex z__1, z__2;

    /* Builtin functions */
    double atan(doublereal), log(doublereal);
    integer pow_ii(integer *, integer *);
    double cos(doublereal), c_abs(complex *);

    /* Local variables */
    static doublecomplex z__[100000];
    static integer mf, mft, nft;
    extern /* Subroutine */ int cfft_(complex *, integer *);
    static doublereal step, tune;
    static integer maxn2;
    static doublereal tune1, duepi, ftmax;
    static complex zsing[100000];
    extern /* Subroutine */ int zfunr_(doublereal *, doublecomplex *, 
	    doublecomplex *, integer *, doublereal *, doublereal *);
    static doublereal deltat;
    static integer nftmax, npoint;
    static doublereal tunefou;

/* ======================================================================= */

/* SUBROUTINE TUNENEWT */

/* COMPUTES THE TUNE USING A DISCRETE VERSION OF LASKAR METHOD. */
/* IT INCLUDES A NEWTON METHOD FOR THE SEARCH OF THE FREQUENCY. */
/* X, XP ARE THE COORDINATES OF THE ORBIT AND MAXN IS THE */
/* LENGTH IF THE ORBIT. */

/* AUTHOR:     A. BAZZANI - BOLOGNA UNIVERSITY */
/*             R. BARTOLINI - CERN HAS INTRODUCED SOME MODIFICATIONS */

/* ======================================================================= */
/* $OMP THREADPRIVATE(z,zsing,maxn,maxn2,mf,mft,nft,nftmax,npoint, */
/* $OMP&              deltat,ftmax,step,tune,tune1,tunefou,duepi) */
/* ............................................................. */
/*    ESTIMATION OF TUNE WITH FFT */
/* ............................................................. */
    /* Parameter adjustments */
    --xp;
    --x;

    /* Function Body */
    duepi = atan(1.) * 8.;
    mft = (integer) (log((doublereal) (*maxn)) / log(2.));
    npoint = pow_ii(&c__2, &mft);
    maxn2 = *maxn / 2;
    step = duepi / *maxn;
    i__1 = *maxn;
    for (mf = 1; mf <= i__1; ++mf) {
	i__2 = mf - 1;
	i__3 = mf;
	i__4 = mf;
	z__2.r = x[i__3], z__2.i = xp[i__4];
	d__1 = cos(step * (mf - maxn2)) + 1.;
	z__1.r = d__1 * z__2.r, z__1.i = d__1 * z__2.i;
	z__[i__2].r = z__1.r, z__[i__2].i = z__1.i;
	i__2 = mf - 1;
	i__3 = mf - 1;
	zsing[i__2].r = z__[i__3].r, zsing[i__2].i = z__[i__3].i;
    }
    i__1 = -mft;
    cfft_(zsing, &i__1);
/* ............................................................. */
/*   SEARCH FOR MAXIMUM OF FOURIER SPECTRUM */
/* ............................................................. */
    ftmax = 0.;
    nftmax = 0;
    i__1 = npoint;
    for (nft = 1; nft <= i__1; ++nft) {
	if (c_abs(&zsing[nft - 1]) > ftmax) {
	    ftmax = c_abs(&zsing[nft - 1]);
	    nftmax = nft;
	}
    }
    tunefou = (doublereal) (nftmax - 1) / (doublereal) npoint;
    if (tunefou >= .5) {
	tunefou = -(1. - tunefou);
    }
    deltat = 1. / npoint;
    tune1 = tunefou - deltat;
    zfunr_(&tune, zw, z__, maxn, &tune1, &deltat);
    ret_val = tune;
/* ............................................................ */
    return ret_val;
/* ............................................................ */
} /* tunenewt_ */

doublereal tunelasr_(doublereal *x, doublereal *xp, integer *maxn, 
	doublecomplex *zw)
{
    /* System generated locals */
    integer i__1, i__2, i__3, i__4;
    doublereal ret_val;
    doublecomplex z__1;

    /* Builtin functions */
    double atan(doublereal), log(doublereal);
    integer pow_ii(integer *, integer *);
    double c_abs(complex *);

    /* Local variables */
    static doublecomplex z__[100000];
    static integer mf, mft, nft;
    extern /* Subroutine */ int cfft_(complex *, integer *);
    static doublereal step, tune;
    static integer maxn2;
    static doublereal tune1, duepi, ftmax;
    static complex zsing[100000];
    extern /* Subroutine */ int zfunr_(doublereal *, doublecomplex *, 
	    doublecomplex *, integer *, doublereal *, doublereal *);
    static doublereal deltat;
    static integer nftmax, npoint;
    static doublereal tunefou;

/* ======================================================================= */

/* SAME AS TUNENEWT BUT NO HANNING FILTER */

/* AUTHOR:     A. BAZZANI - BOLOGNA UNIVERSITY */
/*             R. BARTOLINI - CERN HAS INTRODUCED SOME MODIFICATIONS */

/* ======================================================================= */
/* $OMP THREADPRIVATE(z,zsing,maxn,maxn2,mf,mft,nft,nftmax,npoint, */
/* $OMP&              deltat,ftmax,step,tune,tune1,tunefou,duepi) */
/* ............................................................. */
/*    ESTIMATION OF TUNE WITH FFT */
/* ............................................................. */
    /* Parameter adjustments */
    --xp;
    --x;

    /* Function Body */
    duepi = atan(1.) * 8.;
    mft = (integer) (log((doublereal) (*maxn)) / log(2.));
    npoint = pow_ii(&c__2, &mft);
    maxn2 = *maxn / 2;
    step = duepi / *maxn;
    i__1 = *maxn;
    for (mf = 1; mf <= i__1; ++mf) {
	i__2 = mf - 1;
	i__3 = mf;
	i__4 = mf;
	z__1.r = x[i__3], z__1.i = xp[i__4];
	z__[i__2].r = z__1.r, z__[i__2].i = z__1.i;
/* no filter */
	i__2 = mf - 1;
	i__3 = mf - 1;
	zsing[i__2].r = z__[i__3].r, zsing[i__2].i = z__[i__3].i;
    }
    i__1 = -mft;
    cfft_(zsing, &i__1);
/* ............................................................. */
/*   SEARCH FOR MAXIMUM OF FOURIER SPECTRUM */
/* ............................................................. */
    ftmax = 0.;
    nftmax = 0;
    i__1 = npoint;
    for (nft = 1; nft <= i__1; ++nft) {
	if (c_abs(&zsing[nft - 1]) > ftmax) {
	    ftmax = c_abs(&zsing[nft - 1]);
	    nftmax = nft;
	}
    }
    tunefou = (doublereal) (nftmax - 1) / (doublereal) npoint;
    if (tunefou >= .5) {
	tunefou = -(1. - tunefou);
    }
    deltat = 1. / npoint;
    tune1 = tunefou - deltat;
    zfunr_(&tune, zw, z__, maxn, &tune1, &deltat);
    ret_val = tune;
    return ret_val;
} /* tunelasr_ */

/* Subroutine */ int zfunr_(doublereal *tune, doublecomplex *zw, 
	doublecomplex *z__, integer *maxn, doublereal *tunea1, doublereal *
	deltat)
{
    /* System generated locals */
    integer i__1, i__2, i__3;
    doublereal d__1;
    doublecomplex z__1, z__2, z__3, z__4;

    /* Builtin functions */
    double atan(doublereal);
    void z_exp(doublecomplex *, doublecomplex *);
    double d_imag(doublecomplex *), z_abs(doublecomplex *);

    /* Local variables */
    static doublereal tunevmax, tunetest[10];
    static integer nc, nd;
    static doublecomplex zd[100000], zf, zu, zfd;
    static doublereal err;
    static integer num;
    static doublereal tune1, tune2, tune3;
    extern /* Subroutine */ int calcr_(doublecomplex *, doublecomplex *, 
	    doublecomplex *, integer *);
    static doublereal duepi, ratio;
    static integer ncont, ntest;
    static doublecomplex ztune;
    static doublereal tunea2, dtune1, dtune2, dtune3;
    static doublecomplex ztune1, ztune2, ztune3;
    static doublereal dtunea1, dtunea2, tuneval[10];

/* ======================================================================= */
/* AUXILIARY ROUTINE USED BY TUNENEWT. */

/* AUTHOR:     A. BAZZANI - BOLOGNA UNIVERSITY */

/* ======================================================================= */
/* $OMP THREADPRIVATE(zd,zf,zfd,ztune,ztune1,ztune2,ztune3,zu, */
/* $OMP&              deltat,dtune1,dtune2,dtune3,dtunea1,dtunea2, */
/* $OMP&              err,ratio,tune1,tune2,tune3,tunea2,tunetest, */
/* $OMP&              tuneval,tunevmax,nc,ncont,nd,ntest,num,duepi) */
/* ............................................................ */
    /* Parameter adjustments */
    --z__;

    /* Function Body */
    duepi = atan(1.) * 8.;
    err = 1e-10;
    zu.r = 0., zu.i = 1.;
/* ............................................................ */
/* .... WE DIVIDE DELTAT IN 5 PARTS */
/* ............................................................ */
    *deltat /= 5.;
/* ............................................................ */
    i__1 = *maxn;
    for (nd = 1; nd <= i__1; ++nd) {
	i__2 = nd - 1;
	d__1 = (doublereal) nd;
	z__2.r = d__1 * zu.r, z__2.i = d__1 * zu.i;
	i__3 = nd;
	z__1.r = z__2.r * z__[i__3].r - z__2.i * z__[i__3].i, z__1.i = z__2.r 
		* z__[i__3].i + z__2.i * z__[i__3].r;
	zd[i__2].r = z__1.r, zd[i__2].i = z__1.i;
    }
/* ............................................................ */
    z__4.r = -zu.r, z__4.i = -zu.i;
    z__3.r = duepi * z__4.r, z__3.i = duepi * z__4.i;
    z__2.r = *tunea1 * z__3.r, z__2.i = *tunea1 * z__3.i;
    z_exp(&z__1, &z__2);
    ztune1.r = z__1.r, ztune1.i = z__1.i;
/* Put calcr calls inline                                                 HRR */
/*      call calcr(ztune1,zf,z,maxn) */
/*      call calcr(ztune1,zfd,zd,maxn) */
    i__1 = *maxn;
    zf.r = z__[i__1].r, zf.i = z__[i__1].i;
    i__1 = *maxn - 1;
    zfd.r = zd[i__1].r, zfd.i = zd[i__1].i;
    for (nd = *maxn - 1; nd >= 1; --nd) {
	z__2.r = zf.r * ztune1.r - zf.i * ztune1.i, z__2.i = zf.r * ztune1.i 
		+ zf.i * ztune1.r;
	i__1 = nd;
	z__1.r = z__2.r + z__[i__1].r, z__1.i = z__2.i + z__[i__1].i;
	zf.r = z__1.r, zf.i = z__1.i;
	z__2.r = zfd.r * ztune1.r - zfd.i * ztune1.i, z__2.i = zfd.r * 
		ztune1.i + zfd.i * ztune1.r;
	i__1 = nd - 1;
	z__1.r = z__2.r + zd[i__1].r, z__1.i = z__2.i + zd[i__1].i;
	zfd.r = z__1.r, zfd.i = z__1.i;
    }
    dtunea1 = zf.r * zfd.r + d_imag(&zf) * d_imag(&zfd);
    num = 1;
    for (ntest = 1; ntest <= 10; ++ntest) {
	tunea2 = *tunea1 + *deltat;
	z__4.r = -zu.r, z__4.i = -zu.i;
	z__3.r = duepi * z__4.r, z__3.i = duepi * z__4.i;
	z__2.r = tunea2 * z__3.r, z__2.i = tunea2 * z__3.i;
	z_exp(&z__1, &z__2);
	ztune2.r = z__1.r, ztune2.i = z__1.i;
/* Put calcr calls inline                                                 HRR */
/*       call calcr(ztune2,zf,z,maxn) */
/*       call calcr(ztune2,zfd,zd,maxn) */
	i__1 = *maxn;
	zf.r = z__[i__1].r, zf.i = z__[i__1].i;
	i__1 = *maxn - 1;
	zfd.r = zd[i__1].r, zfd.i = zd[i__1].i;
	for (nd = *maxn - 1; nd >= 1; --nd) {
	    z__2.r = zf.r * ztune2.r - zf.i * ztune2.i, z__2.i = zf.r * 
		    ztune2.i + zf.i * ztune2.r;
	    i__1 = nd;
	    z__1.r = z__2.r + z__[i__1].r, z__1.i = z__2.i + z__[i__1].i;
	    zf.r = z__1.r, zf.i = z__1.i;
	    z__2.r = zfd.r * ztune2.r - zfd.i * ztune2.i, z__2.i = zfd.r * 
		    ztune2.i + zfd.i * ztune2.r;
	    i__1 = nd - 1;
	    z__1.r = z__2.r + zd[i__1].r, z__1.i = z__2.i + zd[i__1].i;
	    zfd.r = z__1.r, zfd.i = z__1.i;
	}
	dtunea2 = zf.r * zfd.r + d_imag(&zf) * d_imag(&zfd);
	if (dtunea1 <= 0. && dtunea2 >= 0.) {
	    tune1 = *tunea1;
	    tune2 = tunea2;
	    dtune1 = dtunea1;
	    dtune2 = dtunea2;
	    for (ncont = 1; ncont <= 100; ++ncont) {
/* ......Insertion, to avoid /0.0 */
		if (dtune2 != 0.) {
		    ratio = -dtune1 / dtune2;
		} else {
		    ratio = 0.f;
		}
		tune3 = (tune1 + ratio * tune2) / (ratio + 1.);
		z__4.r = -zu.r, z__4.i = -zu.i;
		z__3.r = duepi * z__4.r, z__3.i = duepi * z__4.i;
		z__2.r = tune3 * z__3.r, z__2.i = tune3 * z__3.i;
		z_exp(&z__1, &z__2);
		ztune3.r = z__1.r, ztune3.i = z__1.i;
/* Put calcr calls inline                                                 HRR */
/*            call calcr(ztune3,zf,z,maxn) */
/*            call calcr(ztune3,zfd,zd,maxn) */
/* Execution is slightly faster with two separate loops under -O3 */
		i__1 = *maxn;
		zf.r = z__[i__1].r, zf.i = z__[i__1].i;
		i__1 = *maxn - 1;
		zfd.r = zd[i__1].r, zfd.i = zd[i__1].i;
		for (nd = *maxn - 1; nd >= 1; --nd) {
		    z__2.r = zf.r * ztune3.r - zf.i * ztune3.i, z__2.i = zf.r 
			    * ztune3.i + zf.i * ztune3.r;
		    i__1 = nd;
		    z__1.r = z__2.r + z__[i__1].r, z__1.i = z__2.i + z__[i__1]
			    .i;
		    zf.r = z__1.r, zf.i = z__1.i;
		    z__2.r = zfd.r * ztune3.r - zfd.i * ztune3.i, z__2.i = 
			    zfd.r * ztune3.i + zfd.i * ztune3.r;
		    i__1 = nd - 1;
		    z__1.r = z__2.r + zd[i__1].r, z__1.i = z__2.i + zd[i__1]
			    .i;
		    zfd.r = z__1.r, zfd.i = z__1.i;
		}
		dtune3 = zf.r * zfd.r + d_imag(&zf) * d_imag(&zfd);
		if (dtune3 <= 0.) {
		    if (tune1 == tune3) {
			goto L100;
		    }
		    tune1 = tune3;
		    dtune1 = dtune3;
		} else {
		    if (tune2 == tune3) {
			goto L100;
		    }
		    tune2 = tune3;
		    dtune2 = dtune3;
		}
		if ((d__1 = tune2 - tune1, abs(d__1)) <= err) {
		    goto L100;
		}
	    }
L100:
	    tunetest[num - 1] = tune3;
	    tuneval[num - 1] = z_abs(&zf);
	    ++num;
	}
	*tunea1 = tunea2;
	dtunea1 = dtunea2;
    }
    *tune = tunetest[0];
    tunevmax = tuneval[0];
    i__1 = num - 1;
    for (nc = 2; nc <= i__1; ++nc) {
	if (tunevmax <= tuneval[nc - 1]) {
	    tunevmax = tuneval[nc - 1];
	    *tune = tunetest[nc - 1];
	}
    }
    z__4.r = -zu.r, z__4.i = -zu.i;
    z__3.r = duepi * z__4.r, z__3.i = duepi * z__4.i;
    z__2.r = *tune * z__3.r, z__2.i = *tune * z__3.i;
    z_exp(&z__1, &z__2);
    ztune.r = z__1.r, ztune.i = z__1.i;
    calcr_(&ztune, zw, &z__[1], maxn);
/* ............................................................ */
    return 0;
/* ............................................................ */
} /* zfunr_ */

/* Subroutine */ int calcr_(doublecomplex *zv, doublecomplex *zpp, 
	doublecomplex *zp, integer *maxd)
{
    /* System generated locals */
    integer i__1;
    doublecomplex z__1, z__2;

    /* Local variables */
    static integer np;

/* ======================================================================= */
/* AUXILIARY ROUTINE USED BY TUNENEWT. */

/* AUTHOR:     A. BAZZANI - BOLOGNA UNIVERSITY */

/* ======================================================================= */
/* $OMP THREADPRIVATE(np) */
    /* Parameter adjustments */
    --zp;

    /* Function Body */
    i__1 = *maxd;
    zpp->r = zp[i__1].r, zpp->i = zp[i__1].i;
/* ............................................................ */
    for (np = *maxd - 1; np >= 1; --np) {
	z__2.r = zpp->r * zv->r - zpp->i * zv->i, z__2.i = zpp->r * zv->i + 
		zpp->i * zv->r;
	i__1 = np;
	z__1.r = z__2.r + zp[i__1].r, z__1.i = z__2.i + zp[i__1].i;
	zpp->r = z__1.r, zpp->i = z__1.i;
    }
/* ............................................................ */
    return 0;
/* ............................................................ */
} /* calcr_ */

/* Subroutine */ int susres_(integer *nfile, integer *nsus, integer *max__, 
	integer *idams)
{
    /* System generated locals */
    integer i__1, i__2, i__3, i__4, i__5;
    doublereal d__1;
    doublecomplex z__1, z__2;

    /* Builtin functions */
    double atan(doublereal);
    void z_exp(doublecomplex *, doublecomplex *);
    double d_imag(doublecomplex *);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer j, k;
    static doublereal ss, xx, yy, ssp, xxp;
    static doublecomplex zts;
    static doublereal yyp;
    static doublecomplex zss[100000], zxs[100000], ztx, zty, zys[100000];
    static doublereal duepi;
    static doublecomplex zpots, zpotx, zpoty;

    /* Fortran I/O blocks */
    static cilist io___196 = { 0, 0, 0, "(2(G21.15,1X))", 0 };
    static cilist io___197 = { 0, 0, 0, "(4(G21.15,1X))", 0 };
    static cilist io___198 = { 0, 0, 0, "(6(G21.15,1X))", 0 };


/* ======================================================================= */

/* SUBROUTINE SUSRES */

/* SUBTRACTS TO THE SIGNALS THE NEXT TO LEADING FREQUENCIES */
/* LEAVING THE TUNE IN. */

/* NSUS = HARMONICS TO BE SUBTRACTED */
/* MAX  = LENGTH OF THE SIGNAL */
/* NFILE = THE OUTPUT FILE WITH THE SUBTRACTED SIGNAL */

/* THIS ROUTINE MUST BE CALLED ONLY AFTER THE EXECUTION OF */
/* THE ROUTINE DATSPE WHICH FILLS THE COMMONS */

/* AUTHOR: R.BARTOLINI */
/* LAST MODIFIED: 01/04/1996 */

/* ======================================================================= */
/* $OMP THREADPRIVATE(/data/,/fcoe/,/tune/, */
/* $OMP&              j,k,max, */
/* $OMP&              duepi,ss,ssp,xx,xxp,yy,yyp, */
/* $OMP&              zpots,zpotx,zpoty,zts,ztx,zty,zxs,zys,zss) */
    duepi = atan(1.) * 8;
/*      write(6,*)'STARTING THE SUBTRACTION PROCEDURE IN FILE',nfile */
/* ....BUILD THE COMPLEX SIGNAL Z = X + i PX */
    i__1 = *max__;
    for (j = 1; j <= i__1; ++j) {
	i__2 = j - 1;
	i__3 = j - 1;
	i__4 = j - 1;
	z__1.r = data_1.x[i__3], z__1.i = data_1.xp[i__4];
	zxs[i__2].r = z__1.r, zxs[i__2].i = z__1.i;
	i__2 = j - 1;
	i__3 = j - 1;
	i__4 = j - 1;
	z__1.r = data_1.y[i__3], z__1.i = data_1.yp[i__4];
	zys[i__2].r = z__1.r, zys[i__2].i = z__1.i;
	i__2 = j - 1;
	i__3 = j - 1;
	i__4 = j - 1;
	z__1.r = data_1.s[i__3], z__1.i = data_1.sp[i__4];
	zss[i__2].r = z__1.r, zss[i__2].i = z__1.i;
    }
    i__1 = *nsus;
    for (j = 2; j <= i__1; ++j) {
	zpotx.r = 1., zpotx.i = 0.;
	d__1 = tune_1.txa[j - 1] * duepi;
	z__2.r = 0., z__2.i = d__1;
	z_exp(&z__1, &z__2);
	ztx.r = z__1.r, ztx.i = z__1.i;
	zpoty.r = 1., zpoty.i = 0.;
	d__1 = tune_1.tya[j - 1] * duepi;
	z__2.r = 0., z__2.i = d__1;
	z_exp(&z__1, &z__2);
	zty.r = z__1.r, zty.i = z__1.i;
	zpots.r = 1., zpots.i = 0.;
	d__1 = tune_1.tsa[j - 1] * duepi;
	z__2.r = 0., z__2.i = d__1;
	z_exp(&z__1, &z__2);
	zts.r = z__1.r, zts.i = z__1.i;
	i__2 = *max__;
	for (k = 1; k <= i__2; ++k) {
	    i__3 = k - 1;
	    i__4 = k - 1;
	    i__5 = j - 1;
	    z__2.r = fcoe_1.zxpes[i__5].r * zpotx.r - fcoe_1.zxpes[i__5].i * 
		    zpotx.i, z__2.i = fcoe_1.zxpes[i__5].r * zpotx.i + 
		    fcoe_1.zxpes[i__5].i * zpotx.r;
	    z__1.r = zxs[i__4].r - z__2.r, z__1.i = zxs[i__4].i - z__2.i;
	    zxs[i__3].r = z__1.r, zxs[i__3].i = z__1.i;
	    i__3 = k - 1;
	    i__4 = k - 1;
	    i__5 = j - 1;
	    z__2.r = fcoe_1.zypes[i__5].r * zpoty.r - fcoe_1.zypes[i__5].i * 
		    zpoty.i, z__2.i = fcoe_1.zypes[i__5].r * zpoty.i + 
		    fcoe_1.zypes[i__5].i * zpoty.r;
	    z__1.r = zys[i__4].r - z__2.r, z__1.i = zys[i__4].i - z__2.i;
	    zys[i__3].r = z__1.r, zys[i__3].i = z__1.i;
	    i__3 = k - 1;
	    i__4 = k - 1;
	    i__5 = j - 1;
	    z__2.r = fcoe_1.zspes[i__5].r * zpots.r - fcoe_1.zspes[i__5].i * 
		    zpots.i, z__2.i = fcoe_1.zspes[i__5].r * zpots.i + 
		    fcoe_1.zspes[i__5].i * zpots.r;
	    z__1.r = zss[i__4].r - z__2.r, z__1.i = zss[i__4].i - z__2.i;
	    zss[i__3].r = z__1.r, zss[i__3].i = z__1.i;
	    z__1.r = zpotx.r * ztx.r - zpotx.i * ztx.i, z__1.i = zpotx.r * 
		    ztx.i + zpotx.i * ztx.r;
	    zpotx.r = z__1.r, zpotx.i = z__1.i;
	    z__1.r = zpoty.r * zty.r - zpoty.i * zty.i, z__1.i = zpoty.r * 
		    zty.i + zpoty.i * zty.r;
	    zpoty.r = z__1.r, zpoty.i = z__1.i;
	    z__1.r = zpots.r * zts.r - zpots.i * zts.i, z__1.i = zpots.r * 
		    zts.i + zpots.i * zts.r;
	    zpots.r = z__1.r, zpots.i = z__1.i;
	}
    }
/* ....WRITES THE REMAINING SIGNAL */
    i__1 = *max__;
    for (k = 1; k <= i__1; ++k) {
	i__2 = k - 1;
	xx = zxs[i__2].r;
	xxp = d_imag(&zxs[k - 1]);
	i__2 = k - 1;
	yy = zys[i__2].r;
	yyp = d_imag(&zys[k - 1]);
	i__2 = k - 1;
	ss = zss[i__2].r;
	ssp = d_imag(&zss[k - 1]);
	if (*idams == 1) {
	    io___196.ciunit = *nfile;
	    s_wsfe(&io___196);
	    do_fio(&c__1, (char *)&xx, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&xxp, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	} else if (*idams == 2) {
	    io___197.ciunit = *nfile;
	    s_wsfe(&io___197);
	    do_fio(&c__1, (char *)&xx, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&xxp, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&yy, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&yyp, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	} else if (*idams == 3) {
	    io___198.ciunit = *nfile;
	    s_wsfe(&io___198);
	    do_fio(&c__1, (char *)&xx, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&xxp, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&yy, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&yyp, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&ss, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&ssp, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
    }
    return 0;
} /* susres_ */

/* Subroutine */ int ordres_(doublereal *eps, integer *narm, integer *nr, 
	integer *ir, integer *idam, integer *iunit, integer *nturn, 
	doublereal *tunex, doublereal *tuney, doublereal *tunez, integer *
	istune, doublereal *etune, doublereal *tunexy, doublereal *amplitude, 
	doublereal *phase, doublereal *ox, doublereal *ax, doublereal *oy, 
	doublereal *ay)
{
    /* System generated locals */
    integer i__1, i__2, i__3, i__4, i__5;
    doublereal d__1, d__2;
    cllist cl__1;

    /* Builtin functions */
    double atan(doublereal);
    integer f_clos(cllist *);
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);
    double z_abs(doublecomplex *), d_imag(doublecomplex *), atan2(doublereal, 
	    doublereal);

    /* Local variables */
    static integer j, k, l, m, n, j1, k1, l1, m1;
    static doublereal dt, az, ex, ey, ez, fx;
    static integer nt;
    static doublereal fy, fz, pi, px, py, pz, tx[300], ty[300], tz[300], dty, 
	    fxt, fyt, fzt;
    static integer ntx, nty, ntz;
    static doublereal pxt, pyt, pzt, txt, tyt, tzt;
    static doublecomplex zpx, zpy, zpz;
    static integer isca;
    static doublereal ordc, epsx, epsy, epsz, pxti, pyti, pzti, dtxz, dtyz, 
	    pxtr, pytr, pztr;
    static integer narm2, iscax, iscay, iscaz;
    static doublereal ordcx, ordcy, ordcz;
    static integer imiss, myint, flagad[19];
    static doublereal checkn;
    static integer isearx, iseary, isearz;
    static doublereal dtunex, dtuney, dtunez;
    static integer imissx, imissy, imissz;

    /* Fortran I/O blocks */
    static cilist io___207 = { 0, 6, 0, 0, 0 };
    static cilist io___210 = { 0, 6, 0, 0, 0 };
    static cilist io___211 = { 0, 6, 0, 0, 0 };
    static cilist io___228 = { 0, 6, 0, 0, 0 };
    static cilist io___230 = { 0, 6, 0, 0, 0 };
    static cilist io___231 = { 0, 6, 0, 0, 0 };
    static cilist io___233 = { 0, 6, 0, 0, 0 };
    static cilist io___240 = { 0, 6, 0, 0, 0 };
    static cilist io___242 = { 0, 6, 0, 0, 0 };
    static cilist io___270 = { 0, 6, 0, 0, 0 };
    static cilist io___272 = { 0, 6, 0, 0, 0 };


/* ======================================================================= */

/*  ORDERS THE HARMONICS FOUND BY SPECTRUM */

/*  INPUT PARAMETERS: */

/*  NARM : NUMBER OF HARMONICS TO BE OREDERED */
/*  NR   : MAXIMUM ORDER OF HARMONIC TO BE LOOKED FOR IN THE LINEAR */
/*         COMBINATIONS. (NR<10 ALTRIMENTI L'OUTPUT PUO INCASINARSI) */
/*  IR   : FLAG FOR COMPLEX OR REAL SIGNALS: */
/*         1 = INPUT SIGNAL IS REAL. */
/*         N.B. EVEN IF THE SIGNAL IS REAL THE SPECTRUM IS NOT */
/*              TRANSPOSED IN [0,0.5] */
/*  EPS  : MAXIMUM ERROR ACCEPTED TO FIND THE LINEAR COMBINATIONS. */
/*  TUNEX,TUNEZ,TUNES ARE THE EXPECTED TUNES WITHIN 0.01 */

/*  MIND :  THE INPUT DATA COME FROM THE COMMON, SO THIS ROUTINE */
/*          MUST BE USED ONLY AFTER THE CALL TO DATSPE */
/*          THE ARRAYS TX,TY,TZ ARE USED IN ORDER NOT TO CHANGE */
/*          THE ARRAYS TXA,TYA,TSA. */

/*  THE OUTPUT IS PLACED IN THE FILE FORT.300 WHICH IS NOT CLOSED AT THE */
/*  END OF THE SUBROUTINE IN ORDER TO COLLECT THE RESULTS OF DIFFERENT */
/*  SIGNALS IN ONE FILE ONLY. THE DIFFERENT SIGNALS ARE NUMBERED BY IOU. */

/*  A CHECK IS PERFORMED TO SEE IF THE HARMONICS ARE CLOSER THAN 1/NTURN */

/*  IOU  : INDEX WHICH IDENTIFIES THE CASE ANALIZED */

/*  AUTHOR: R.BARTOLINI 12/02/1996 */
/*  LAST MODIFIED: 21/09/1997 */

/* ======================================================================= */
/* $OMP THREADPRIVATE(/fcoe/,/tune/, */
/* $OMP&imiss,imissx,imissy,imissz,isca,iscax,iscay,iscaz, */
/* $OMP&isearx,iseary,isearz,j,j1,k,k1,l,l1,m,m1,n, */
/* $OMP&narm2,nt,ntx,nty,ntz,flagad,myint, */
/* $OMP&pi, */
/* $OMP&az,checkn,dt,dtunex,dtuney,dtunez,dtxz,dty,dtyz, */
/* $OMP&epsx,epsy,epsz,ex,ey,ez,fx,fxt,fy,fyt,fz,fzt,ordc,ordcx, */
/* $OMP&ordcy,ordcz,px,pxt,pxti,pxtr,py,pyt,pyti,pytr,pz,pzt,pzti,pztr, */
/* $OMP&tx,txt,ty,tyt,tz,tzt, */
/* $OMP&zpx,zpy,zpz) */
    /* Parameter adjustments */
    --ay;
    --oy;
    --ax;
    --ox;
    --phase;
    --amplitude;
    --tunexy;
    --etune;

    /* Function Body */
    pi = atan(1.) * 4;
    checkn = 1. / (doublereal) (*nturn);
    flagad[0] = 0;
    flagad[1] = 0;
    flagad[2] = 0;
    flagad[3] = 0;
    flagad[4] = 0;
    flagad[5] = 0;
    flagad[6] = 0;
    flagad[7] = 0;
    flagad[8] = 0;
    flagad[9] = 0;
    flagad[10] = 0;
    flagad[11] = 0;
    flagad[12] = 0;
    flagad[13] = 0;
    flagad[14] = 0;
    flagad[15] = 0;
    flagad[16] = 0;
    flagad[17] = 0;
    flagad[18] = 0;
    if (*nr > 10) {
/*        write(6,*)'ERROR IN ORDRES: NR LARGER THAN 10' */
	cl__1.cerr = 0;
	cl__1.cunit = 10;
	cl__1.csta = 0;
	f_clos(&cl__1);
/*        close(30) */
/*        close(iunit) */
	s_stop("", (ftnlen)0);
    }
    i__1 = *narm;
    for (j = 1; j <= i__1; ++j) {
	tx[j - 1] = tune_1.txa[j - 1];
	ty[j - 1] = tune_1.tya[j - 1];
	tz[j - 1] = tune_1.tsa[j - 1];
    }

/* .. TUNES PARAMETERS AND EVENTUAL CHECK FOR THE EXPECTED TUNES */

    if (*istune >= 1) {
/* .....CHECK X TUNE */
	dtunex = (d__1 = abs(tx[0]) - abs(*tunex), abs(d__1));
	if (dtunex > etune[1] || tx[0] * *tunex < 0.) {
	    s_wsle(&io___207);
	    do_lio(&c__9, &c__1, "X TUNE DIFFERENT FROM EXPECTED", (ftnlen)30)
		    ;
	    e_wsle();
/*          write(6,*)-tx(1),-tunex */
	    ntx = 1;
	    i__1 = *narm;
	    for (nt = 2; nt <= i__1; ++nt) {
		dtunex = (d__2 = (d__1 = tx[nt - 1], abs(d__1)) - abs(*tunex),
			 abs(d__2));
		if (dtunex <= etune[1] && tx[nt - 1] * *tunex > 0.) {
		    ntx = nt;
		    goto L7;
		}
	    }
L7:
	    if (ntx > 1) {
		s_wsle(&io___210);
		do_lio(&c__9, &c__1, "EXPECTED TUNE X FOUND AT LINE", (ftnlen)
			29);
		do_lio(&c__3, &c__1, (char *)&ntx, (ftnlen)sizeof(integer));
		e_wsle();
	    } else if (ntx == 1) {
		s_wsle(&io___211);
		do_lio(&c__9, &c__1, "EXPECTED TUNE X NOT FOUND", (ftnlen)25);
		e_wsle();
/*            if(istune.eq.1) write(6,*)'LINE 1 ASSUMED AS TUNE!!!' */
	    }
	    tx[0] = tx[ntx - 1];
	    tx[ntx - 1] = tune_1.txa[0];
	    zpx.r = fcoe_1.zxpes[0].r, zpx.i = fcoe_1.zxpes[0].i;
	    i__1 = ntx - 1;
	    fcoe_1.zxpes[0].r = fcoe_1.zxpes[i__1].r, fcoe_1.zxpes[0].i = 
		    fcoe_1.zxpes[i__1].i;
	    i__1 = ntx - 1;
	    fcoe_1.zxpes[i__1].r = zpx.r, fcoe_1.zxpes[i__1].i = zpx.i;
	}
    }
    if (*istune == 2) {
	txt = *tunex;
    } else {
	txt = tx[0];
    }
    pxt = z_abs(fcoe_1.zxpes);
/* ..... Insertion to avoid /0.0 */
    if (pxt > 0.) {
	pxtr = fcoe_1.zxpes[0].r / pxt;
	pxti = d_imag(fcoe_1.zxpes) / pxt;
	fxt = atan2(pxti, pxtr);
    } else if (pxt == 0.) {
	pxtr = 0.;
	pxti = 0.;
	fxt = 0.;
    }
    fxt = fxt / pi * 180.;
    tyt = 9999.f;
    tzt = 8888.f;
    if (*idam >= 2) {
	if (*istune >= 1) {
/* .....CHECK Y TUNE */
	    dtuney = (d__1 = abs(ty[0]) - abs(*tuney), abs(d__1));
	    if (dtuney > etune[2] || ty[0] * *tuney < 0.) {
/*            write(6,*)'Y TUNE DIFFERENT FROM EXPECTED' */
/*            write(6,*)-ty(1),-tuney */
		nty = 1;
		i__1 = *narm;
		for (nt = 2; nt <= i__1; ++nt) {
		    dtuney = (d__2 = (d__1 = ty[nt - 1], abs(d__1)) - abs(*
			    tuney), abs(d__2));
		    if (dtuney <= etune[2] && ty[nt - 1] * *tuney > 0.) {
			nty = nt;
			goto L8;
		    }
		}
L8:
		if (nty > 1) {
/*              write(6,*)'EXPECTED TUNE Y FOUND AT LINE',nty */
		} else if (nty == 1) {
/*              write(6,*)'EXPECTED TUNE Y NOT FOUND' */
/*              if(istune.eq.1) write(6,*)'LINE 1 ASSUMED AS TUNE!!!' */
		}
		ty[0] = ty[nty - 1];
		ty[nty - 1] = tune_1.tya[0];
		zpy.r = fcoe_1.zypes[0].r, zpy.i = fcoe_1.zypes[0].i;
		i__1 = nty - 1;
		fcoe_1.zypes[0].r = fcoe_1.zypes[i__1].r, fcoe_1.zypes[0].i = 
			fcoe_1.zypes[i__1].i;
		i__1 = nty - 1;
		fcoe_1.zypes[i__1].r = zpy.r, fcoe_1.zypes[i__1].i = zpy.i;
	    }
	}
	if (*istune == 2) {
	    tyt = *tuney;
	} else {
	    tyt = ty[0];
	}
	pyt = z_abs(fcoe_1.zypes);
/* .... Insertion to avoid /0.0 */
	if (pyt > 0.) {
	    pytr = fcoe_1.zypes[0].r / pyt;
	    pyti = d_imag(fcoe_1.zypes) / pyt;
	    fyt = atan2(pyti, pytr);
	} else if (pyt == 0.) {
	    pytr = 0.f;
	    pyti = 0.f;
	    fyt = 0.f;
	}
	fyt = fyt / pi * 180.;
	dty = (d__1 = tyt - txt, abs(d__1));
	if (dty <= *eps) {
	    s_wsle(&io___228);
	    do_lio(&c__9, &c__1, "TUNEX AND TUNEY ARE TOO CLOSE", (ftnlen)29);
	    e_wsle();
	    tyt = 9999.f;
	}
    } else if (*idam < 2 && *istune == 2) {
	tyt = *tuney;
    }
    if (*idam == 3) {
	if (*istune >= 1) {
/* .....CHECK Z TUNE */
	    dtunez = (d__1 = abs(tz[0]) - abs(*tunez), abs(d__1));
	    if (dtunez > etune[3] || tz[0] * *tunez < 0.) {
		s_wsle(&io___230);
		do_lio(&c__9, &c__1, "Y TUNE DIFFERENT FROM EXPECTED", (
			ftnlen)30);
		e_wsle();
		s_wsle(&io___231);
		d__1 = -tz[0];
		do_lio(&c__5, &c__1, (char *)&d__1, (ftnlen)sizeof(doublereal)
			);
		d__2 = -(*tunez);
		do_lio(&c__5, &c__1, (char *)&d__2, (ftnlen)sizeof(doublereal)
			);
		e_wsle();
		ntz = 1;
		i__1 = *narm;
		for (nt = 2; nt <= i__1; ++nt) {
		    dtunez = (d__2 = (d__1 = tz[nt - 1], abs(d__1)) - abs(*
			    tunez), abs(d__2));
		    if (dtunez <= etune[3] && tz[nt - 1] * *tunez > 0.) {
			ntz = nt;
			goto L9;
		    }
		}
L9:
		if (ntz > 1) {
/*              write(6,*)'EXPECTED TUNE S FOUND AT LINE',ntz */
		} else if (ntz == 1) {
		    s_wsle(&io___233);
		    do_lio(&c__9, &c__1, "EXPECTED TUNE S NOT FOUND", (ftnlen)
			    25);
		    e_wsle();
/*              if(istune.eq.1) write(6,*)'LINE 1 ASSUMED AS TUNE!!!' */
		}
		tz[0] = tz[ntz - 1];
		tz[ntz - 1] = tune_1.tsa[0];
		zpz.r = fcoe_1.zspes[0].r, zpz.i = fcoe_1.zspes[0].i;
		i__1 = ntz - 1;
		fcoe_1.zspes[0].r = fcoe_1.zspes[i__1].r, fcoe_1.zspes[0].i = 
			fcoe_1.zspes[i__1].i;
		i__1 = ntz - 1;
		fcoe_1.zspes[i__1].r = zpz.r, fcoe_1.zspes[i__1].i = zpz.i;
	    }
	}
	if (*istune == 2) {
	    tzt = *tunez;
	} else {
	    tzt = tz[0];
	}
	pzt = z_abs(fcoe_1.zspes);
	pztr = fcoe_1.zspes[0].r / pzt;
	pzti = d_imag(fcoe_1.zspes) / pzt;
	fzt = atan2(pzti, pztr);
	fzt = fzt / pi * 180.;
	dtxz = (d__1 = tzt - txt, abs(d__1));
	if (dtxz <= *eps) {
	    s_wsle(&io___240);
	    do_lio(&c__9, &c__1, "TUNEX AND TUNES ARE TOO CLOSE", (ftnlen)29);
	    e_wsle();
	    tzt = 8888.f;
	}
	dtyz = (d__1 = tzt - tyt, abs(d__1));
	if (dtyz <= *eps) {
	    s_wsle(&io___242);
	    do_lio(&c__9, &c__1, "TUNEY AND TUNES ARE TOO CLOSE", (ftnlen)29);
	    e_wsle();
	    tzt = 8888.f;
	}
    } else if (*idam < 3 && *istune == 2) {
	tzt = *tunez;
    }

/* .. X SIGNAL PROCESSING */

/*      write(30,*) */
/*      write(30,*)'ANALYSIS OF X SIGNAL, CASE:',iunit */
/*      write(30,*)'TUNE X = ',-txt */
/*      write(30,*) */
/*      write(30,'(3a)')'        Line Frequency      Amplitude', */
/*     &'             Phase       ', */
/*     &'      Error         mx  my  ms  p' */
/*      write(30,*) */
    iscax = 0;
    imissx = 0;
    i__1 = *narm;
    for (n = 1; n <= i__1; ++n) {
	ox[n] = -tx[n - 1];
	ax[n] = z_abs(&fcoe_1.zxpes[n - 1]);
/* .....CHECK WITH PREVIOUS HARMONICS */
	i__2 = n - 1;
	for (k = 1; k <= i__2; ++k) {
	    dt = (d__1 = tx[k - 1] - tx[n - 1], abs(d__1));
	    if (dt <= checkn) {
		iscax = 1;
	    }
	}
/* .....SEARCH LINEAR COMBINATIONS */
	isearx = 0;
	ordcx = 3e3;
/* large number needed here */
	i__2 = *nr;
	for (l = -(*nr); l <= i__2; ++l) {
	    i__3 = *nr;
	    for (m = -(*nr); m <= i__3; ++m) {
		i__4 = *nr;
		for (k = -(*nr); k <= i__4; ++k) {
		    i__5 = *nr;
		    for (j = -(*nr); j <= i__5; ++j) {
			az = l * txt + m * tyt + k * tzt + j;
			ex = (d__1 = az - tx[n - 1], abs(d__1));
			if (ex < *eps) {
			    ++isearx;
/* .....check for the lowest possible order of combination */
			    ordc = (doublereal) (abs(l) + abs(m) + abs(k));
			    if (ordc < ordcx) {
				l1 = l;
				m1 = m;
				k1 = k;
				j1 = j;
				epsx = ex;
				ordcx = ordc;
			    }
			}
		    }
		}
	    }
	}
	if (isearx >= 1) {
	    px = z_abs(&fcoe_1.zxpes[n - 1]);
	    if (px > 0.) {
		i__2 = n - 1;
		pxtr = fcoe_1.zxpes[i__2].r / px;
		pxti = d_imag(&fcoe_1.zxpes[n - 1]) / px;
		fx = atan2(pxti, pxtr);
		fx = fx / pi * 180.;
/* ...  Insertion, to return parameters */
/*            write(*,*) l1, m1, k1, j1, flagad(1), tx(n) */
		if (l1 == 1 && m1 == 0 && k1 == 0 && j1 == 0 && flagad[0] == 
			0) {
		    amplitude[1] = px;
		    phase[1] = -fx;
		    tunexy[1] = -tx[n - 1];
		    flagad[0] = 1;
		}
		if (l1 == -2 && m1 == 0 && k1 == 0 && flagad[1] == 0) {
		    amplitude[2] = px;
		    phase[2] = -fx;
		    flagad[1] = 1;
		}
		if (flagad[2] == 0 && l1 == 0 && m1 == 1 && k1 == 0) {
		    amplitude[3] = px;
		    phase[3] = -fx;
		    flagad[2] = 1;
		}
		if (flagad[6] == 0 && l1 == -3 && m1 == 0 && k1 == 0) {
		    amplitude[7] = px;
		    phase[7] = -fx;
		    flagad[6] = 1;
		}
		if (flagad[7] == 0 && l1 == -4 && m1 == 0 && k1 == 0) {
		    amplitude[8] = px;
		    phase[8] = -fx;
		    flagad[7] = 1;
		}
		if (flagad[8] == 0 && l1 == -5 && m1 == 0 && k1 == 0 && j1 == 
			0) {
		    amplitude[9] = px;
		    phase[9] = -fx;
		    flagad[8] = 1;
		}
		if (flagad[9] == 0 && l1 == 2 && m1 == 0 && k1 == 0) {
		    amplitude[10] = px;
		    phase[10] = -fx;
		    flagad[9] = 1;
		}
		if (flagad[10] == 0 && l1 == 0 && m1 == 0 && k1 == 0) {
		    amplitude[11] = px;
		    phase[11] = -fx;
		    flagad[10] = 1;
		}
		if (flagad[12] == 0 && l1 == 0 && m1 == 2 && k1 == 0 && j1 == 
			0) {
		    amplitude[13] = px;
		    phase[13] = -fx;
		    flagad[12] = 1;
		}
		if (l1 == -1 && m1 == -1 && k1 == 0 && j1 == 0 && flagad[14] 
			== 0) {
		    amplitude[15] = px;
		    phase[15] = -fx;
		    flagad[14] = 1;
		}
		if (l1 == 2 && m1 == -2 && k1 == 0 && j1 == 0 && flagad[16] ==
			 0) {
		    amplitude[17] = px;
		    phase[17] = -fx;
		    flagad[16] = 1;
		}
		if (l1 == 0 && m1 == -2 && k1 == 0 && j1 == 0 && flagad[18] ==
			 0) {
		    amplitude[19] = px;
		    phase[19] = -fx;
		    flagad[18] = 1;
		}
/* ...  End of Insertion */
/*            write(30,100)n,-tx(n),px,-fx,epsx,l1,m1,k1,j1 */
	    } else if (px == 0.) {
/*            write(30,100)n,-tx(n),px,0,0 */
	    }
	} else if (isearx == 0) {
	    ++imissx;
	    px = z_abs(&fcoe_1.zxpes[n - 1]);
	    if (px > 0.) {
		i__2 = n - 1;
		pxtr = fcoe_1.zxpes[i__2].r / px;
		pxti = d_imag(&fcoe_1.zxpes[n - 1]) / px;
		fx = atan2(pxti, pxtr);
		fx = fx / pi * 180.;
/*            write(30,100)n,-tx(n),px,-fx,eps */
	    } else if (px == 0.) {
/*           write(30,100)n,-tx(n),px,0,0 */
	    }
	}
/* L10: */
    }

/* .. Y SIGNAL PROCESSING */

    if (*idam < 2) {
/*        write(30,*) */
/*        write(30,*) 'NO Y SIGNAL' */
	if (*istune == 2) {
/*          write(30,*) 'TUNE Y = ',-tyt */
/*          write(30,*) 'TUNE S = ',-tzt */
	    goto L51;
	} else {
/*          write(30,*) */
/*          write(30,*) */
	    goto L50;
	}
    }
/*      write(30,*) */
/*      write(30,*) 'ANALYSIS OF Y SIGNAL, CASE:',iunit */
    if (*istune == 2) {
/*        write(30,*) 'TUNE Y = ',-tyt */
    } else {
/*        write(30,*) 'TUNE Y = ',-ty(1) */
    }
/*      write(30,*) */
/*      write(30,'(3a)')'        Line Frequency      Amplitude', */
/*     &'             Phase       ', */
/*     &'      Error         mx  my  ms  p' */
/*     write(30,*) */
    iscay = 0;
    imissy = 0;
    i__1 = *narm;
    for (n = 1; n <= i__1; ++n) {
/* .....CHECK WITH PREVIOUS HARMONICS */
	i__2 = n - 1;
	for (k = 1; k <= i__2; ++k) {
	    dt = (d__1 = ty[k - 1] - ty[n - 1], abs(d__1));
	    if (dt <= checkn) {
		iscay = 1;
	    }
	}
/* .....SEARCH LINEAR COMBINATIONS */
	iseary = 0;
	ordcy = 3e3;
/* large number needed here */
	i__2 = *nr;
	for (l = -(*nr); l <= i__2; ++l) {
	    i__3 = *nr;
	    for (m = -(*nr); m <= i__3; ++m) {
		i__4 = *nr;
		for (k = -(*nr); k <= i__4; ++k) {
		    i__5 = *nr;
		    for (j = -(*nr); j <= i__5; ++j) {
			az = l * txt + m * tyt + k * tzt + j;
			ey = (d__1 = az - ty[n - 1], abs(d__1));
			if (ey < *eps) {
			    ++iseary;
/* .....check for the lowest possible order of combination */
			    ordc = (doublereal) (abs(l) + abs(m) + abs(k));
			    if (ordc < ordcy) {
				l1 = l;
				m1 = m;
				k1 = k;
				j1 = j;
				epsy = ey;
				ordcy = ordc;
			    }
			}
		    }
		}
	    }
	}
	if (iseary >= 1) {
	    py = z_abs(&fcoe_1.zypes[n - 1]);
	    if (py > 0.) {
		i__2 = n - 1;
		pytr = fcoe_1.zypes[i__2].r / py;
		pyti = d_imag(&fcoe_1.zypes[n - 1]) / py;
		fy = atan2(pyti, pytr);
		fy = fy / pi * 180.;
/* ...  Insertion, to return parameters */
		if (n == 1) {
		    amplitude[4] = py;
		    s_wsle(&io___270);
		    do_lio(&c__9, &c__1, "p3 ", (ftnlen)3);
		    do_lio(&c__5, &c__1, (char *)&fy, (ftnlen)sizeof(
			    doublereal));
		    do_lio(&c__5, &c__1, (char *)&py, (ftnlen)sizeof(
			    doublereal));
		    do_lio(&c__5, &c__1, (char *)&ty[n - 1], (ftnlen)sizeof(
			    doublereal));
		    do_lio(&c__5, &c__1, (char *)&tunexy[1], (ftnlen)sizeof(
			    doublereal));
		    e_wsle();
		    phase[4] = -fy;
		    tunexy[2] = -ty[n - 1];
		}
		if (l1 == 0 && m1 == 1 && k1 == 0 && j1 == 0 && flagad[3] == 
			0) {
		    amplitude[4] = py;
		    phase[4] = -fy;
		    tunexy[2] = -ty[n - 1];
/*              write(*,*)"p32 ", fy, py, ty(n) */
		    flagad[3] = 1;
		}
		if (l1 == 0 && m1 == -2 && k1 == 0 && flagad[4] == 0) {
		    amplitude[5] = py;
		    phase[5] = -fy;
		    flagad[4] = 1;
		}
		if (flagad[5] == 0 && l1 == 1 && m1 == 0 && k1 == 0 && j1 == 
			0) {
		    amplitude[6] = py;
		    phase[6] = -fy;
		    flagad[5] = 1;
		}
		if (flagad[11] == 0 && l1 == 0 && m1 == -3 && k1 == 0 && j1 ==
			 0) {
		    amplitude[12] = py;
		    phase[12] = -fy;
		    flagad[11] = 1;
		}
		if (flagad[13] == 0 && l1 == -1 && m1 == -1 && k1 == 0 && j1 
			== 0) {
		    amplitude[14] = py;
		    phase[14] = -fy;
		    flagad[13] = 1;
		}
		if (l1 == -2 && m1 == 0 && k1 == 0 && flagad[15] == 0) {
		    amplitude[16] = py;
		    phase[16] = -fy;
		    flagad[15] = 1;
		}
		if (l1 == 1 && m1 == -1 && k1 == 0 && flagad[17] == 0) {
		    amplitude[18] = py;
		    phase[18] = -fy;
		    flagad[17] = 1;
		}
/* ...  End of Insertion */
		oy[n] = -ty[n - 1];
		ay[n] = py;
/*            write(30,100)n,-ty(n),py,-fy,epsy,l1,m1,k1,j1 */
	    } else if (py == 0.) {
		oy[n] = -ty[n - 1];
		ay[n] = py;
/*            write(30,100)n,-ty(n),py,0,0 */
	    }
	} else if (iseary == 0) {
	    ++imissy;
	    py = z_abs(&fcoe_1.zypes[n - 1]);
	    if (py > 0.) {
		i__2 = n - 1;
		pytr = fcoe_1.zypes[i__2].r / py;
		pyti = d_imag(&fcoe_1.zypes[n - 1]) / py;
		fy = atan2(pyti, pytr);
		fy = fy / pi * 180.;
		oy[n] = -ty[n - 1];
		ay[n] = py;
/*            write(30,100)n,-ty(n),py,-fy,eps */
	    } else if (py == 0.) {
		oy[n] = -ty[n - 1];
		ay[n] = py;
/*            write(30,100)n,-ty(n),py,0,0 */
	    }
	}
    }
    for (myint = 1; myint <= 19; ++myint) {
	if (flagad[myint - 1] == 0) {
	    amplitude[myint] = 0.;
	    phase[myint] = 0.;
	    if (myint == 1) {
		tunexy[1] = 0.;
	    }
	    if (myint == 4) {
		tunexy[2] = 0.;
		s_wsle(&io___272);
		do_lio(&c__9, &c__1, "VERTICAL TUNE NOT IDENTIFIED (in sussi"
			"x)", (ftnlen)40);
		e_wsle();
	    }
	}
    }

/* .. S SIGNAL PROCESSING */

L51:
    if (*idam < 3) {
/*        write(30,*) */
/*        write(30,*) 'NO S SIGNAL' */
	if (*istune == 2) {
/*          write(30,*) 'TUNE S = ',-tzt */
	} else {
/*          write(30,*) */
	}
/*        write(30,*) */
	goto L50;
    }
/*      write(30,*) */
/*      write(30,*) 'ANALYSIS OF S SIGNAL, CASE:',iunit */
    if (*istune == 2) {
/*        write(30,*) 'TUNE S = ',-tzt */
    } else {
/*        write(30,*) 'TUNE S = ',-tz(1) */
    }
/*      write(30,*) */
/*      write(30,'(3a)')'        Line Frequency      Amplitude', */
/*     &'             Phase       ', */
/*     &'      Error         mx  my  ms  p' */
/*      write(30,*) */
    iscaz = 0;
    imissz = 0;
    i__1 = *narm;
    for (n = 1; n <= i__1; ++n) {
/* .....CHECK WITH PREVIOUS HARMONICS */
	i__2 = n - 1;
	for (k = 1; k <= i__2; ++k) {
	    dt = (d__1 = tz[k - 1] - tz[n - 1], abs(d__1));
	    if (dt <= checkn) {
		iscaz = 1;
	    }
	}
/* .....SEARCH LINEAR COMBINATIONS */
	isearz = 0;
	ordcz = 3e3;
/* large number needed here */
	i__2 = *nr;
	for (l = -(*nr); l <= i__2; ++l) {
	    i__3 = *nr;
	    for (m = -(*nr); m <= i__3; ++m) {
		i__4 = *nr;
		for (k = -(*nr); k <= i__4; ++k) {
		    i__5 = *nr;
		    for (j = -(*nr); j <= i__5; ++j) {
			az = l * txt + m * tyt + k * tzt + j;
			ez = (d__1 = az - tz[n - 1], abs(d__1));
			if (ez < *eps) {
			    ++isearz;
/* .....check for the lowest possible order of combination */
			    ordc = (doublereal) (abs(l) + abs(m) + abs(k));
			    if (ordc < ordcz) {
				l1 = l;
				m1 = m;
				k1 = k;
				j1 = j;
				epsz = ez;
				ordcz = ordc;
			    }
			}
		    }
		}
	    }
	}
	if (isearz >= 1) {
	    pz = z_abs(&fcoe_1.zspes[n - 1]);
	    i__2 = n - 1;
	    pztr = fcoe_1.zspes[i__2].r / pz;
	    pzti = d_imag(&fcoe_1.zspes[n - 1]) / pz;
	    fz = atan2(pzti, pztr);
	    fz = fz / pi * 180.;
/*          write(30,100)n,-tz(n),pz,-fz,epsz,l1,m1,k1,j1 */
	} else if (isearz == 0) {
	    ++imissz;
	    pz = z_abs(&fcoe_1.zspes[n - 1]);
	    i__2 = n - 1;
	    pztr = fcoe_1.zspes[i__2].r / pz;
	    pzti = d_imag(&fcoe_1.zspes[n - 1]) / pz;
	    fz = atan2(pzti, pztr);
	    fz = fz / pi * 180.;
/*          write(30,100)n,-tz(n),pz,-fz,eps */
	}
/* L30: */
    }
L50:
/* 50    write(6,*)'================================================' */
/*      write(6,*)'HARMONICS NON-IDENTIFIED IN X = ',imissx */
/*      write(6,*)'HARMONICS NON-IDENTIFIED IN Y = ',imissy */
/*      write(6,*)'HARMONICS NON-IDENTIFIED IN S = ',imissz */
    narm2 = (integer) (*narm / 2.);
    imiss = imissx + imissy + imissz;
    if (imiss >= *narm) {
/*       write(6,*)'WARNING: CHECK EPS' */
    }
    isca = iscax + iscay + iscaz;
    if (isca >= 1) {
/*        write(6,*)'WARNING: TOO CLOSE BY HARMONICS DETECTED' */
/*        write(6,*)'WARNING: TRY A LARGER NUMBER OF TURNS' */
    }
/*      write(6,*)'WROTE IN FORT.300 THE SPECTRAL ANALYSIS OF CASE:',iunit */
/*      write(6,*)'================================================' */
/* L100: */
    return 0;
} /* ordres_ */

/* Subroutine */ int datspe_(doublereal *xy, doublereal *eps, integer *iunit, 
	integer *idam, integer *ir, integer *nt1, integer *nt2, integer *
	nturn, integer *imeth, integer *narm, integer *nrc, integer *iana)
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    double atan(doublereal);

    /* Local variables */
    extern /* Subroutine */ int spectrum_(doublereal *, doublereal *, integer 
	    *, doublereal *, doublecomplex *, integer *, integer *);
    static integer j, k;
    extern /* Subroutine */ int fftr_(doublereal *, doublereal *, integer *, 
	    complex *, integer *);
    static doublereal duepi;
    static complex zsing;
    static integer nturn2;

/* ======================================================================= */

/*  SUBROUTINE DATSPE */

/*  THIS PROGRAM CALCULATES THE SPECTRUM OF A SINGLE FILE */
/*  OF TRACKING DATA WRITTEN IN A STANDARD ASCII FROM IN 2*IDAM COLUMNS. */

/*  WITH THE DATA SOME INFORMATIONS ARE REQUESTED: */

/*    IUNIT = FORTRAN UNIT OF INPUT DATA */
/*    IDAM  = DIMENSION OF PHASE SPACE */
/*    IR    = FLAG FOR REAL SIGNAL (1=REAL) */
/*    NT1   = INITIAL TURN TO BE ANALYZED */
/*    NT2   = FINAL TURN TO BE ANALYZED */

/*  THE TUNE AND THE LINES ARE CALCULATED WITH THE ROUTINE SPECTRUM */

/*    NARM : THE NUMBER OF HARMONIC TO BE CALCULATED */
/*    IMETH: THE CHIOCE ON THE WINDOWING */
/*           1 HANNING WINDOW (TUNENEWT) */
/*           2 NO WINDOW (TUNELASR) */
/*    NRC   = ORDER OF LINEAR COMBINATIONS TO LOOK FOR */
/*    EPS   = TOLERANCE ON LINEAR COMBINATIONS */

/*  N.B.: ONLY ONE FILE IS ANALIZED AND THE OUTPUT IS PLACED IN */
/*        THE COMMONS TUNE AND FCOE TOGETHER WITH THE TRACKING DATA. */
/*  N.B.: NTURN IS AN OUTPUT PARAMETER! */

/*  AUTHOR: R.BARTOLINI 21/08/1996 */
/*  MODIFIED 17/09/1996: ADDED THE IR OPTION */
/*  MODIFIED 30/05/1998: ADDED FFT */

/* ======================================================================= */
/* $OMP THREADPRIVATE(/data/,/fcoe/,/tune/,j,nturn2,k,zsing,duepi) */
    /* Parameter adjustments */
    --xy;

    /* Function Body */
    duepi = atan(1.) * 8;
/* .....READ INPUT FILE */
/*      write(6,*)'****************************' */
/*      write(6,*)'ANALYZING UNIT',iunit */
/*      write(6,*)'****************************' */
    if (*idam == 1) {
	for (j = 1; j <= 10000; ++j) {
/*        do j=1,4000 */
/*        do j=1,maxn */
/*         read(iunit,*,end=990)x(j),xp(j) */
	    data_1.x[j - 1] = xy[j];
	    data_1.xp[j - 1] = xy[j];
	}
    } else if (*idam == 2) {
	for (j = 1; j <= 10000; ++j) {
/*        do j=1,4000 */
/*        do j=1,maxn */
/*          read(iunit,*,end=990)x(j),xp(j),y(j),yp(j) */
	    data_1.x[j - 1] = xy[j];
	    data_1.xp[j - 1] = xy[j + 20000];
	    data_1.y[j - 1] = xy[j + 10000];
	    data_1.yp[j - 1] = xy[j + 30000];
	}
    } else if (*idam == 3) {
	for (j = 1; j <= 100000; ++j) {
/*          read(iunit,*,end=990)x(j),xp(j),y(j),yp(j),s(j),sp(j) */
	}
    }
/* 990   nturn=j-1       ! check this it is always larger by 1 */
    *nturn = j - 1;
/*      write(6,*)'NUMBER OF TURNS DETECTED IN THE INPUT',nturn */
/*      rewind(iunit) */
/* .....CHECK FOR REQUIRED SECTIONING OF THE SIGNAL */
    nturn2 = *nt2 - *nt1 + 1;
    if (*nturn > nturn2) {
	if (*idam == 1) {
	    i__1 = nturn2;
	    for (k = 1; k <= i__1; ++k) {
		data_1.x[k - 1] = data_1.x[*nt1 + k - 2];
		data_1.xp[k - 1] = data_1.xp[*nt1 + k - 2];
	    }
	} else if (*idam == 2) {
	    i__1 = nturn2;
	    for (k = 1; k <= i__1; ++k) {
		data_1.x[k - 1] = data_1.x[*nt1 + k - 2];
		data_1.xp[k - 1] = data_1.xp[*nt1 + k - 2];
		data_1.y[k - 1] = data_1.y[*nt1 + k - 2];
		data_1.yp[k - 1] = data_1.yp[*nt1 + k - 2];
	    }
	} else if (*idam == 3) {
	    i__1 = nturn2;
	    for (k = 1; k <= i__1; ++k) {
		data_1.x[k - 1] = data_1.x[*nt1 + k - 2];
		data_1.xp[k - 1] = data_1.xp[*nt1 + k - 2];
		data_1.y[k - 1] = data_1.y[*nt1 + k - 2];
		data_1.yp[k - 1] = data_1.yp[*nt1 + k - 2];
		data_1.s[k - 1] = data_1.s[*nt1 + k - 2];
		data_1.sp[k - 1] = data_1.sp[*nt1 + k - 2];
	    }
	}
	*nturn = nturn2;
/*        write(6,*)'REDUCTION OF THE SIGNAL PERFORMED.' */
/*        write(6,*)'NEW NUMBER OF TURNS ANALYZED =',nturn */
/*        write(6,*)'INTERVAL',nt1,nt2 */
    }
/* .....FLAG FOR THE ANALYSIS OF THE REAL PART ONLY */
    if (*ir == 1) {
	i__1 = *nturn;
	for (j = 1; j <= i__1; ++j) {
	    data_1.xp[j - 1] = 0.;
	    data_1.yp[j - 1] = 0.;
	    data_1.sp[j - 1] = 0.;
	}
/*        write(6,*)'WARNING: ONLY THE REAL PART OF THE SIGNAL IS' */
/*        write(6,*)'         CONSIDERED FOR SPECTRUM CALCULATION' */
    }
/* .....SPECTRUM CALCULATION */
    if (*idam == 1) {
	spectrum_(data_1.x, data_1.xp, nturn, tune_1.txa, fcoe_1.zxpes, narm, 
		imeth);
/*        write(6,*)'TURNS ANALYZED AND TUNE' */
/*        write(6,*)nturn,-txa(1) */
	if (*iana == 2) {
	    fftr_(data_1.x, data_1.xp, nturn, &zsing, imeth);
	}
    } else if (*idam == 2) {
	spectrum_(data_1.x, data_1.xp, nturn, tune_1.txa, fcoe_1.zxpes, narm, 
		imeth);
	spectrum_(data_1.y, data_1.yp, nturn, tune_1.tya, fcoe_1.zypes, narm, 
		imeth);
/*        write(6,*)'TURNS ANALYZED AND TUNE' */
/*        write(6,*)nturn,-txa(1),-tya(1) */
	if (*iana == 2) {
	    fftr_(data_1.x, data_1.xp, nturn, &zsing, imeth);
	    fftr_(data_1.y, data_1.yp, nturn, &zsing, imeth);
	}
    } else if (*idam == 3) {
	spectrum_(data_1.x, data_1.xp, nturn, tune_1.txa, fcoe_1.zxpes, narm, 
		imeth);
	spectrum_(data_1.y, data_1.yp, nturn, tune_1.tya, fcoe_1.zypes, narm, 
		imeth);
	spectrum_(data_1.s, data_1.sp, nturn, tune_1.tsa, fcoe_1.zspes, narm, 
		imeth);
/*        write(6,*)'TURNS ANALYZED AND TUNE' */
/*        write(6,*)nturn,-txa(1),-tya(1),-tsa(1) */
	if (*iana == 2) {
	    fftr_(data_1.x, data_1.xp, nturn, &zsing, imeth);
	    fftr_(data_1.y, data_1.yp, nturn, &zsing, imeth);
	    fftr_(data_1.s, data_1.sp, nturn, &zsing, imeth);
	}
    }
    return 0;
} /* datspe_ */

/* Subroutine */ int fftr_(doublereal *x, doublereal *xp, integer *maxn, 
	complex *zsing, integer *meth)
{
    /* System generated locals */
    integer i__1, i__2, i__3, i__4;
    doublereal d__1;
    doublecomplex z__1, z__2;

    /* Builtin functions */
    double atan(doublereal), log(doublereal);
    integer pow_ii(integer *, integer *);
    double cos(doublereal), c_abs(complex *), r_imag(complex *), atan2(
	    doublereal, doublereal);

    /* Local variables */
    static doublecomplex z__[100000];
    static integer mf, nf;
    static doublereal pha, amp;
    static integer mft;
    extern /* Subroutine */ int cfft_(complex *, integer *);
    static doublereal omnf, step;
    static integer maxn2;
    static doublereal duepi;
    static integer npoint;

/* ======================================================================= */

/* SUBROUTINE FFTR */

/* COMPUTES THE FFT. */
/* X, XP ARE THE COORDINATES OF THE ORBIT AND MAXN IS THE */
/* LENGTH IF THE ORBIT. */

/* METH SELECTS THE HANNING WINDOW (1) OR NOT (2) */

/* FOURIER COEFFICIENTS ARE GIVEN IN ZSING */
/* AND THE SPECTRUM IS WRITTEN IN FORT.301 */

/* AUTHOR:     R. BARTOLINI */

/* ======================================================================= */
/* $OMP THREADPRIVATE(z,amp,omnf,pha,step,maxn2,mf,mft,nf,npoint,duepi) */
/* ............................................................. */
/*    ESTIMATION OF TUNE WITH FFT */
/* ............................................................. */
    /* Parameter adjustments */
    --zsing;
    --xp;
    --x;

    /* Function Body */
    duepi = atan(1.) * 8.;
    mft = (integer) (log((doublereal) (*maxn)) / log(2.));
    npoint = pow_ii(&c__2, &mft);
    maxn2 = *maxn / 2;
    step = duepi / *maxn;
    if (*meth == 1) {
	i__1 = *maxn;
	for (mf = 1; mf <= i__1; ++mf) {
	    i__2 = mf - 1;
	    i__3 = mf;
	    i__4 = mf;
	    z__2.r = x[i__3], z__2.i = xp[i__4];
	    d__1 = cos(step * (mf - maxn2)) + 1.;
	    z__1.r = d__1 * z__2.r, z__1.i = d__1 * z__2.i;
	    z__[i__2].r = z__1.r, z__[i__2].i = z__1.i;
	    i__2 = mf;
	    i__3 = mf - 1;
	    zsing[i__2].r = z__[i__3].r, zsing[i__2].i = z__[i__3].i;
	}
    } else if (*meth == 2) {
	i__1 = *maxn;
	for (mf = 1; mf <= i__1; ++mf) {
	    i__2 = mf - 1;
	    i__3 = mf;
	    i__4 = mf;
	    z__1.r = x[i__3], z__1.i = xp[i__4];
	    z__[i__2].r = z__1.r, z__[i__2].i = z__1.i;
	    i__2 = mf;
	    i__3 = mf - 1;
	    zsing[i__2].r = z__[i__3].r, zsing[i__2].i = z__[i__3].i;
	}
    }
    i__1 = -mft;
    cfft_(&zsing[1], &i__1);
    i__1 = npoint;
    for (nf = 1; nf <= i__1; ++nf) {
	omnf = (nf - 1.) / npoint;
	amp = c_abs(&zsing[nf]);
	pha = atan2(r_imag(&zsing[nf]), (real) zsing[nf].r) / duepi * 360;
/*        write(301,*)omnf,amp/npoint,pha */
    }
/* ............................................................ */
    return 0;
/* ............................................................ */
} /* fftr_ */

/* Subroutine */ int readres_(integer *imin, integer *imax, integer *lr, 
	integer *mr, integer *kr, integer *narm, integer *idam, integer *
	idamx, integer *iout)
{
    /* Builtin functions */
    double atan(doublereal);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static doublereal pi;
    static char ch1[200];
    static integer istep;

/* ======================================================================= */

/*  SUBROUTINE READRES */

/*  READ THE HARMONICS FROM THE FILE FORT.300 */
/*  AND WRITE SEPARATELY THE SELECTED ONE */

/*  INPUT PARAMETERS: */

/*  IMIN,IMAX ENUMERATE THE DIFFERENT CASES STORED IN THE FORT.300 */
/*  NARM : NUMERO DI ARMONICHE DA ORDINARE */
/*  IR   : FLAG FOR COMPLEX OR REAL SIGNALS: */
/*         1 = INPUT SIGNAL IS REAL. */

/*  N.B. :  THE STRENGTH OF NEXT TO LEADING LINES ARE NORMALIZED AT THE */
/*          TUNE STRENGTH. */
/*  MIND :  THE ARRAYS TX,TY,TZ ARE USED IN ORDER NOT TO CHANGE */
/*          THE ARRAYS TUNEX,TUNEY,TUNEZ. */

/*  IOU  : FORTRAN UNIT OF THE OUTPUT, IF 0 NO OUTPUT */

/*  AUTHOR: R.BARTOLINI 21/08/1996 */
/*  LAST MODIFIED 08/10/1997 */

/* ======================================================================= */
/* $OMP THREADPRIVATE(/dt/, */
/* $OMP&              i,ifoun,istep,j,k,ki,l,m,n,ni, */
/* $OMP&              ex,fx,pi,px,tx,ch,ch1) */
    pi = atan(1.) * 4;
    s_copy(ch1, " ", (ftnlen)200, (ftnlen)1);
    if (*imin <= *imax) {
	istep = 1;
    } else {
	istep = -1;
    }
/*      rewind(30) */
/*      do 3 i=imin,imax,istep */
/* C        write(6,*)'ANALYZING UNIT 300 FOR LINE IDENTIFICATION CASE:',i */
/*        do ki=1,idam */
/* 1        read(30,'(A)',end=2) ch */
/* Find start for each plane */
/*          if(ch(1:9).eq.' ANALYSIS') then */
/*            read(30,'()',end=2) */
/*            read(30,'()',end=2) */
/*            read(30,'()',end=2) */
/*            read(30,'()',end=2) */
/*            ifoun=0 */
/*            do ni=1,narm */
/*              read(30,'(A)',end=2) ch */
/*              ch(198:200)=' / ' */
/* Detect end of data and exit to 3 to study next plane */
/*              if(ch.eq.ch1) goto 3 */
/*              l=-9999 */
/*              m=-9999 */
/*              k=-9999 */
/*              j=-9999 */
/*              read(ch,*)n,tx(n),px,fx,ex,l,m,k,j */
/*              if(ki.eq.idamx) then */
/*                if((l.eq.lr.and.m.eq.mr.and.k.eq.kr).and. */
/*     &            ifoun.eq.0) then */
/*                  if(iout.ne.0) then */
/*                    write(iout,101)tx(1),tx(ni),px,fx,ex,l,m,k,j, */
/*     &              ' CASE:',i */
/*                  endif */
/* Fills the vector for eventual DT calculation */
/*                  dtpx(i)=px */
/*                  dtfx(i)=fx */
/*                  dttx(i)=tx(ni) */
/*                  ifoun=1 */
/*                endif */
/*              endif */
/*            enddo */
/*            if(ki.eq.idamx.and.ifoun.eq.0.and.iout.ne.0) write(iout,*) */
/*          else */
/*            goto 1 */
/*          endif */
/*        enddo */
/* 3    continue */
/* 2    continue */
/*     rewind(30) */
/* 101   format(4(1x,e18.12),1x,e17.12,:,4(1x,i3),a6,1x,i3) */
    return 0;
} /* readres_ */

/* Subroutine */ int readdt3_(integer *imin, integer *imax, integer *narm, 
	integer *idam, integer *idamx, integer *iout)
{
    /* Format strings */
    static char fmt_100[] = "(1x,a4,4(1x,e19.13))";
    static char fmt_200[] = "(1x,a4,2(1x,e19.13))";

    /* System generated locals */
    integer i__1, i__2, i__3;
    doublereal d__1, d__2;
    doublecomplex z__1, z__2, z__3, z__4;

    /* Builtin functions */
    double atan(doublereal);
    integer s_wsle(cilist *), e_wsle(void), do_lio(integer *, integer *, char 
	    *, ftnlen), s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), 
	    e_wsfe(void);
    double cos(doublereal), sin(doublereal);
    void z_exp(doublecomplex *, doublecomplex *);
    double z_abs(doublecomplex *), d_imag(doublecomplex *), atan2(doublereal, 
	    doublereal);

    /* Local variables */
    static integer i__;
    static doublereal y1, y2, pi, fx[50], fy[50], px[50], py[50], tx[50], ty[
	    50], a0012, a0030, a1002, a1011, a1020, a1110, a1200, a2001, 
	    a2010, a3000, c0012, c0030, c1002, c1011, c1020, c1110, c1200, 
	    c2001, c2010, c3000, f0012, f0030, f1002, f1011, f1020, f1110, 
	    f1200, f2001, f2010, f3000, s0012, s0030, s1002, s1011, s1020, 
	    s1110, s1200, s2001, s2010, s3000;
    static doublecomplex z1011, z2100;
    static doublereal aaux[50], faux[50];
    static doublecomplex zfli, zline;
    static integer istep;
    extern /* Subroutine */ int readres_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *);

    /* Fortran I/O blocks */
    static cilist io___305 = { 0, 0, 0, 0, 0 };
    static cilist io___306 = { 0, 0, 0, 0, 0 };
    static cilist io___307 = { 0, 0, 0, 0, 0 };
    static cilist io___308 = { 0, 0, 0, "(2a)", 0 };
    static cilist io___309 = { 0, 0, 0, 0, 0 };
    static cilist io___365 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___366 = { 0, 0, 0, fmt_200, 0 };
    static cilist io___367 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___368 = { 0, 0, 0, fmt_200, 0 };
    static cilist io___369 = { 0, 0, 0, 0, 0 };
    static cilist io___370 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___371 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___372 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___373 = { 0, 0, 0, fmt_200, 0 };
    static cilist io___374 = { 0, 0, 0, fmt_200, 0 };
    static cilist io___375 = { 0, 0, 0, fmt_200, 0 };
    static cilist io___376 = { 0, 0, 0, 0, 0 };
    static cilist io___377 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___378 = { 0, 0, 0, fmt_200, 0 };
    static cilist io___379 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___380 = { 0, 0, 0, fmt_200, 0 };
    static cilist io___381 = { 0, 0, 0, 0, 0 };
    static cilist io___382 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___383 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___384 = { 0, 0, 0, fmt_200, 0 };
    static cilist io___385 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___386 = { 0, 0, 0, fmt_200, 0 };
    static cilist io___387 = { 0, 0, 0, fmt_200, 0 };


/* ======================================================================= */

/*  SUBROUTINE READDT3 */

/*  READ THE HARMONICS FROM THE FILE FORT.300 */
/*  AND CONVERT THEM INTO DRIVING TERMS (SEE LHC Project Report 132) */

/*  INPUT PARAMETERS: */

/*  IMIN,IMAX ENUMERATE THE DIFFERENT CASES STORED IN THE FORT.300 */
/*  NARM : NUMERO DI ARMONICHE DA ORDINARE */
/*  IR   : FLAG FOR COMPLEX OR REAL SIGNALS: */
/*         1 = INPUT SIGNAL IS REAL. */


/*  IOUT  : FORTRAN UNIT OF THE OUTPUT */

/*  AUTHOR: R.BARTOLINI 21/08/1996 */

/* ======================================================================= */
/* $OMP THREADPRIVATE(/dt/, */
/* $OMP&              i,istep, */
/* $OMP&a0012,a0030,a1002,a1011,a1020,a1110,a1200,a2001, */
/* $OMP&a2010,a3000,aaux,c0012,c0030,c1002,c1011,c1020,c1110,c1200,c2001, */
/* $OMP&c2010,c3000,f0012,f0030,f1002,f1011,f1020,f1110,f1200,f2001,f2010, */
/* $OMP&f3000,faux,fx,fy,pi,px,py,s0012,s0030,s1002,s1011,s1020,s1110, */
/* $OMP&s1200,s2001,s2010,s3000,tx,ty,y1,y2, */
/* $OMP&z1011,z2100,zfli,zline) */
    pi = atan(1.) * 4;
    if (*imin <= *imax) {
	istep = 1;
    } else {
	istep = -1;
    }
    io___305.ciunit = *iout;
    s_wsle(&io___305);
    e_wsle();
    io___306.ciunit = *iout;
    s_wsle(&io___306);
    do_lio(&c__9, &c__1, "THIRD ORDER CONJUGATING FUNCTION COEFFICIENTS", (
	    ftnlen)45);
    e_wsle();
    io___307.ciunit = *iout;
    s_wsle(&io___307);
    e_wsle();
    io___308.ciunit = *iout;
    s_wsfe(&io___308);
    do_fio(&c__1, "jklm          Amplitude              Phase", (ftnlen)42);
    do_fio(&c__1, "           Cos             Sin", (ftnlen)30);
    e_wsfe();
    io___309.ciunit = *iout;
    s_wsle(&io___309);
    e_wsle();
    i__1 = *imax;
    i__2 = istep;
    for (i__ = *imin; i__2 < 0 ? i__ >= i__1 : i__ <= i__1; i__ += i__2) {
/* tune lines */
	dt_1.dtpx[i__ - 1] = 0.;
	dt_1.dtfx[i__ - 1] = 0.;
	dt_1.dttx[i__ - 1] = 0.;
	readres_(imin, &i__, &c__1, &c__0, &c__0, narm, idam, &c__1, &c__0);
	tx[i__ - 1] = dt_1.dttx[i__ - 1];
	px[i__ - 1] = dt_1.dtpx[i__ - 1];
	fx[i__ - 1] = dt_1.dtfx[i__ - 1];
	if (*idam >= 2) {

/* attenzione se analizzo il moto verticale ci */
/* va la y. cosi come e' faccio un overwrite su dtpx,dtfx,sttx */

/* inoltre la linea eccitata in orizzontale */
/* e' 1-j+k,m-l e non l-m */
/* idem per il vertical avro' k-j e non j-k */
/* correggere. */

	    dt_1.dtpx[i__ - 1] = 0.;
	    dt_1.dtfx[i__ - 1] = 0.;
	    dt_1.dttx[i__ - 1] = 0.;
	    readres_(imin, &i__, &c__0, &c__1, &c__0, narm, idam, &c__2, &
		    c__0);
	    ty[i__ - 1] = dt_1.dttx[i__ - 1];
	    py[i__ - 1] = dt_1.dtpx[i__ - 1];
	    fy[i__ - 1] = dt_1.dtfx[i__ - 1];
	}
/* CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC */
/* One dimensional resonances horizontal C */
/* CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC */
/* -2,0 line and h3000 */
	dt_1.dtpx[i__ - 1] = 0.;
	dt_1.dtfx[i__ - 1] = 0.;
	dt_1.dttx[i__ - 1] = 0.;
	readres_(imin, &i__, &c_n2, &c__0, &c__0, narm, idam, &c__1, &c__0);
/* Computing 2nd power */
	d__1 = px[i__ - 1];
	a3000 = dt_1.dtpx[i__ - 1] / 2. / 3. / (d__1 * d__1);
	f3000 = dt_1.dtfx[i__ - 1] - fx[i__ - 1] + 90.;
	c3000 = a3000 * cos(f3000 / 180 * pi);
	s3000 = a3000 * sin(f3000 / 180 * pi);
/* 2,0 line and h1200 */
	dt_1.dtpx[i__ - 1] = 0.;
	dt_1.dtfx[i__ - 1] = 0.;
	dt_1.dttx[i__ - 1] = 0.;
	readres_(imin, &i__, &c__2, &c__0, &c__0, narm, idam, &c__1, &c__0);
/* Computing 2nd power */
	d__1 = px[i__ - 1];
	a1200 = dt_1.dtpx[i__ - 1] / 2. / (d__1 * d__1);
	f1200 = dt_1.dtfx[i__ - 1] - fx[i__ - 1] + 90.;
	c1200 = a1200 * cos(f1200 / 180 * pi);
	s1200 = a1200 * sin(f1200 / 180 * pi);
/* stores this data for eventual subresonance calculation */
	aaux[i__ - 1] = a1200;
	faux[i__ - 1] = f1200;
/* other lines in case of 4D motion */
	if (*idam > 1) {
/* CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC */
/* One dimensional vertical resonances (vertical motion needed) C */
/* CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC */
/* 0,-2 line and h0030 */
	    dt_1.dtpx[i__ - 1] = 0.;
	    dt_1.dtfx[i__ - 1] = 0.;
	    dt_1.dttx[i__ - 1] = 0.;
	    readres_(imin, &i__, &c__0, &c_n2, &c__0, narm, idam, &c__2, &
		    c__0);
/* Computing 2nd power */
	    d__1 = py[i__ - 1];
	    a0030 = dt_1.dtpx[i__ - 1] / 2. / 3. / (d__1 * d__1);
	    f0030 = dt_1.dtfx[i__ - 1] - fy[i__ - 1] + 90.;
	    c0030 = a0030 * cos(f0030 / 180 * pi);
	    s0030 = a0030 * sin(f0030 / 180 * pi);
/* 0,2 line and h0012 */
	    dt_1.dtpx[i__ - 1] = 0.;
	    dt_1.dtfx[i__ - 1] = 0.;
	    dt_1.dttx[i__ - 1] = 0.;
	    readres_(imin, &i__, &c__0, &c__2, &c__0, narm, idam, &c__2, &
		    c__0);
/* Computing 2nd power */
	    d__1 = py[i__ - 1];
	    a0012 = dt_1.dtpx[i__ - 1] / 2. / (d__1 * d__1);
	    f0012 = dt_1.dtfx[i__ - 1] - fy[i__ - 1] + 90.;
	    c0012 = a0012 * cos(f0012 / 180 * pi);
	    s0012 = a0012 * sin(f0012 / 180 * pi);
/* CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC */
/* Normal resonances from horizontal motion C */
/* CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC */
/* 0,-2 line and h1020 */
	    dt_1.dtpx[i__ - 1] = 0.;
	    dt_1.dtfx[i__ - 1] = 0.;
	    dt_1.dttx[i__ - 1] = 0.;
	    readres_(imin, &i__, &c__0, &c_n2, &c__0, narm, idam, &c__1, &
		    c__0);
/* Computing 2nd power */
	    d__1 = py[i__ - 1];
	    a1020 = dt_1.dtpx[i__ - 1] / 2. / (d__1 * d__1);
	    f1020 = dt_1.dtfx[i__ - 1] - fx[i__ - 1] + 90.;
	    c1020 = a1020 * cos(f1020 / 180 * pi);
	    s1020 = a1020 * sin(f1020 / 180 * pi);
/* 0,2 line and h1002 */
	    dt_1.dtpx[i__ - 1] = 0.;
	    dt_1.dtfx[i__ - 1] = 0.;
	    dt_1.dttx[i__ - 1] = 0.;
	    readres_(imin, &i__, &c__0, &c__2, &c__0, narm, idam, &c__1, &
		    c__0);
/* Computing 2nd power */
	    d__1 = py[i__ - 1];
	    a1002 = dt_1.dtpx[i__ - 1] / 2. / (d__1 * d__1);
	    f1002 = dt_1.dtfx[i__ - 1] - fx[i__ - 1] + 90.;
	    c1002 = a1002 * cos(f1002 / 180 * pi);
	    s1002 = a1002 * sin(f1002 / 180 * pi);
/* 0,0 line and h1011 --subresonance: h2100 needed--- */
	    dt_1.dtpx[i__ - 1] = 0.;
	    dt_1.dtfx[i__ - 1] = 0.;
	    dt_1.dttx[i__ - 1] = 0.;
	    readres_(imin, &i__, &c__0, &c__0, &c__0, narm, idam, &c__1, &
		    c__0);
	    i__3 = i__ - 1;
	    d__1 = dt_1.dtfx[i__ - 1] / 180 * pi;
	    z__3.r = 0., z__3.i = d__1;
	    z_exp(&z__2, &z__3);
	    z__1.r = dt_1.dtpx[i__3] * z__2.r, z__1.i = dt_1.dtpx[i__3] * 
		    z__2.i;
	    zline.r = z__1.r, zline.i = z__1.i;
/* .......rebulding the contribution to the (0,0) from h2100 */
/* Computing 2nd power */
	    d__2 = px[i__ - 1];
	    d__1 = d__2 * d__2 * 4;
	    z__1.r = d__1 * 0., z__1.i = d__1 * -1.;
	    zfli.r = z__1.r, zfli.i = z__1.i;
	    i__3 = i__ - 1;
	    d__1 = -faux[i__ - 1] / 180 * pi;
	    z__4.r = 0., z__4.i = d__1;
	    z_exp(&z__3, &z__4);
	    z__2.r = aaux[i__3] * z__3.r, z__2.i = aaux[i__3] * z__3.i;
	    z__1.r = z__2.r * zfli.r - z__2.i * zfli.i, z__1.i = z__2.r * 
		    zfli.i + z__2.i * zfli.r;
	    z2100.r = z__1.r, z2100.i = z__1.i;
/* .......subtracting the contribution from h2100 to the (0,0) */
	    z__1.r = zline.r - z2100.r, z__1.i = zline.i - z2100.i;
	    z1011.r = z__1.r, z1011.i = z__1.i;
/* .......building h1011 from z1011 */
/* Computing 2nd power */
	    d__1 = py[i__ - 1];
	    a1011 = z_abs(&z1011) / 2. / (d__1 * d__1);
	    y1 = z1011.r;
	    y2 = d_imag(&z1011);
	    f1011 = atan2(y2, y1) * 180 / pi - fx[i__ - 1] + 90.;
	    c1011 = a1011 * cos(f1011 / 180 * pi);
	    s1011 = a1011 * sin(f1011 / 180 * pi);
/* CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC */
/* Skew resonances from horizontal motion C */
/* CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC */
/* -1,-1 line and h2010 */
	    dt_1.dtpx[i__ - 1] = 0.;
	    dt_1.dtfx[i__ - 1] = 0.;
	    dt_1.dttx[i__ - 1] = 0.;
	    readres_(imin, &i__, &c_n1, &c_n1, &c__0, narm, idam, &c__1, &
		    c__0);
	    a2010 = dt_1.dtpx[i__ - 1] / 2. / 2. / px[i__ - 1] / py[i__ - 1];
	    f2010 = dt_1.dtfx[i__ - 1] - fx[i__ - 1] + 90.;
	    c2010 = a2010 * cos(f2010 / 180 * pi);
	    s2010 = a2010 * sin(f2010 / 180 * pi);
/*  1,-1 line and h1110 */
	    dt_1.dtpx[i__ - 1] = 0.;
	    dt_1.dtfx[i__ - 1] = 0.;
	    dt_1.dttx[i__ - 1] = 0.;
	    readres_(imin, &i__, &c__1, &c_n1, &c__0, narm, idam, &c__1, &
		    c__0);
	    a1110 = dt_1.dtpx[i__ - 1] / 2. / px[i__ - 1] / py[i__ - 1];
	    f1110 = dt_1.dtfx[i__ - 1] - fx[i__ - 1] + 90.;
	    c1110 = a1110 * cos(f1110 / 180 * pi);
	    s1110 = a1110 * sin(f1110 / 180 * pi);
/* -1,1 line and h2001 */
	    dt_1.dtpx[i__ - 1] = 0.;
	    dt_1.dtfx[i__ - 1] = 0.;
	    dt_1.dttx[i__ - 1] = 0.;
	    readres_(imin, &i__, &c_n1, &c__1, &c__0, narm, idam, &c__1, &
		    c__0);
	    a2001 = dt_1.dtpx[i__ - 1] / 2. / 2. / px[i__ - 1] / py[i__ - 1];
	    f2001 = dt_1.dtfx[i__ - 1] - fx[i__ - 1] + 90.;
	    c2001 = a2001 * cos(f2001 / 180 * pi);
	    s2001 = a2001 * sin(f2001 / 180 * pi);
	}
	io___365.ciunit = *iout;
	s_wsfe(&io___365);
	do_fio(&c__1, "3000", (ftnlen)4);
	do_fio(&c__1, (char *)&a3000, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&f3000, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&c3000, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&s3000, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___366.ciunit = *iout;
	s_wsfe(&io___366);
	do_fio(&c__1, "2100", (ftnlen)4);
	do_fio(&c__1, (char *)&a1200, (ftnlen)sizeof(doublereal));
	d__1 = -f1200;
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___367.ciunit = *iout;
	s_wsfe(&io___367);
	do_fio(&c__1, "1200", (ftnlen)4);
	do_fio(&c__1, (char *)&a1200, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&f1200, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&c1200, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&s1200, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___368.ciunit = *iout;
	s_wsfe(&io___368);
	do_fio(&c__1, "0300", (ftnlen)4);
	do_fio(&c__1, (char *)&a3000, (ftnlen)sizeof(doublereal));
	d__1 = -f3000;
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___369.ciunit = *iout;
	s_wsle(&io___369);
	e_wsle();
	io___370.ciunit = *iout;
	s_wsfe(&io___370);
	do_fio(&c__1, "1020", (ftnlen)4);
	do_fio(&c__1, (char *)&a1020, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&f1020, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&c1020, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&s1020, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___371.ciunit = *iout;
	s_wsfe(&io___371);
	do_fio(&c__1, "1011", (ftnlen)4);
	do_fio(&c__1, (char *)&a1011, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&f1011, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&c1011, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&s1011, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___372.ciunit = *iout;
	s_wsfe(&io___372);
	do_fio(&c__1, "1002", (ftnlen)4);
	do_fio(&c__1, (char *)&a1002, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&f1002, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&c1002, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&s1002, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___373.ciunit = *iout;
	s_wsfe(&io___373);
	do_fio(&c__1, "0120", (ftnlen)4);
	do_fio(&c__1, (char *)&a1002, (ftnlen)sizeof(doublereal));
	d__1 = -f1002;
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___374.ciunit = *iout;
	s_wsfe(&io___374);
	do_fio(&c__1, "0111", (ftnlen)4);
	do_fio(&c__1, (char *)&a1011, (ftnlen)sizeof(doublereal));
	d__1 = -f1011;
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___375.ciunit = *iout;
	s_wsfe(&io___375);
	do_fio(&c__1, "0102", (ftnlen)4);
	do_fio(&c__1, (char *)&a1020, (ftnlen)sizeof(doublereal));
	d__1 = -f1020;
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___376.ciunit = *iout;
	s_wsle(&io___376);
	e_wsle();
	io___377.ciunit = *iout;
	s_wsfe(&io___377);
	do_fio(&c__1, "0030", (ftnlen)4);
	do_fio(&c__1, (char *)&a0030, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&f0030, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&c0030, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&s0030, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___378.ciunit = *iout;
	s_wsfe(&io___378);
	do_fio(&c__1, "0021", (ftnlen)4);
	do_fio(&c__1, (char *)&a0012, (ftnlen)sizeof(doublereal));
	d__1 = -f0012;
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___379.ciunit = *iout;
	s_wsfe(&io___379);
	do_fio(&c__1, "0012", (ftnlen)4);
	do_fio(&c__1, (char *)&a0012, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&f0012, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&c0012, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&s0012, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___380.ciunit = *iout;
	s_wsfe(&io___380);
	do_fio(&c__1, "0003", (ftnlen)4);
	do_fio(&c__1, (char *)&a0030, (ftnlen)sizeof(doublereal));
	d__1 = -f0030;
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___381.ciunit = *iout;
	s_wsle(&io___381);
	e_wsle();
	io___382.ciunit = *iout;
	s_wsfe(&io___382);
	do_fio(&c__1, "2010", (ftnlen)4);
	do_fio(&c__1, (char *)&a2010, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&f2010, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&c2010, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&s2010, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___383.ciunit = *iout;
	s_wsfe(&io___383);
	do_fio(&c__1, "1110", (ftnlen)4);
	do_fio(&c__1, (char *)&a1110, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&f1110, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&c1110, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&s1110, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___384.ciunit = *iout;
	s_wsfe(&io___384);
	do_fio(&c__1, "0210", (ftnlen)4);
	do_fio(&c__1, (char *)&a2001, (ftnlen)sizeof(doublereal));
	d__1 = -f2001;
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___385.ciunit = *iout;
	s_wsfe(&io___385);
	do_fio(&c__1, "2001", (ftnlen)4);
	do_fio(&c__1, (char *)&a2001, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&f2001, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&c2001, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&s2001, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___386.ciunit = *iout;
	s_wsfe(&io___386);
	do_fio(&c__1, "1101", (ftnlen)4);
	do_fio(&c__1, (char *)&a1110, (ftnlen)sizeof(doublereal));
	d__1 = -f1110;
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___387.ciunit = *iout;
	s_wsfe(&io___387);
	do_fio(&c__1, "0201", (ftnlen)4);
	do_fio(&c__1, (char *)&a2010, (ftnlen)sizeof(doublereal));
	d__1 = -f2010;
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    return 0;
} /* readdt3_ */

/* Subroutine */ int readdt4_(integer *imin, integer *imax, integer *narm, 
	integer *idam, integer *idamx, integer *iout)
{
    /* Format strings */
    static char fmt_100[] = "(1x,a4,4(1x,e19.13))";
    static char fmt_200[] = "(1x,a4,2(1x,e19.13))";

    /* System generated locals */
    integer i__1, i__2, i__3;
    doublereal d__1, d__2;
    doublecomplex z__1, z__2, z__3, z__4;

    /* Builtin functions */
    double atan(doublereal);
    integer s_wsle(cilist *), e_wsle(void), do_lio(integer *, integer *, char 
	    *, ftnlen), s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), 
	    e_wsfe(void);
    double cos(doublereal), sin(doublereal);
    void z_exp(doublecomplex *, doublecomplex *);
    double z_abs(doublecomplex *), d_imag(doublecomplex *), atan2(doublereal, 
	    doublereal);

    /* Local variables */
    static integer i__;
    static doublereal y1, y2, pi, fx[50], fy[50], px[50], py[50], tx[50], ty[
	    50], a0013, a0040, a0301, a1003, a1012, a1021, a1030, a1120, 
	    a1201, a1210, a1300, a2002, a2011, a2020, a2101, a3001, a3010, 
	    a4000, c0013, c0040, c1003, c1012, c1021, c1030, c1120, c1201, 
	    c1210, c1300, c2002, c2011, c2020, c3001, c3010, c4000, f0013, 
	    f0040, f1003, f1012, f1021, f1030, f1120, f1201, f1210, f1300, 
	    f2002, f2011, f2020, f3001, f3010, f4000, s0013, s0040, s1003, 
	    s1012, s1021, s1030, s1120, s1201, s1210, s1300, s2002, s2011, 
	    s2020, s3001, s3010, s4000;
    static doublecomplex z1012, z1021, z2011, z2101, z2110, z3100;
    static doublereal aaux[50], aauy[50], faux[50], fauy[50];
    static doublecomplex zfli, zline;
    static integer istep;
    extern /* Subroutine */ int readres_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *);

    /* Fortran I/O blocks */
    static cilist io___390 = { 0, 0, 0, 0, 0 };
    static cilist io___391 = { 0, 0, 0, 0, 0 };
    static cilist io___392 = { 0, 0, 0, 0, 0 };
    static cilist io___393 = { 0, 0, 0, "(2a)", 0 };
    static cilist io___394 = { 0, 0, 0, 0, 0 };
    static cilist io___480 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___481 = { 0, 0, 0, fmt_200, 0 };
    static cilist io___482 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___483 = { 0, 0, 0, fmt_200, 0 };
    static cilist io___484 = { 0, 0, 0, 0, 0 };
    static cilist io___485 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___486 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___487 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___488 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___489 = { 0, 0, 0, fmt_200, 0 };
    static cilist io___490 = { 0, 0, 0, fmt_200, 0 };
    static cilist io___491 = { 0, 0, 0, fmt_200, 0 };
    static cilist io___492 = { 0, 0, 0, fmt_200, 0 };
    static cilist io___493 = { 0, 0, 0, 0, 0 };
    static cilist io___494 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___495 = { 0, 0, 0, fmt_200, 0 };
    static cilist io___496 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___497 = { 0, 0, 0, fmt_200, 0 };
    static cilist io___498 = { 0, 0, 0, 0, 0 };
    static cilist io___499 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___500 = { 0, 0, 0, fmt_200, 0 };
    static cilist io___501 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___502 = { 0, 0, 0, fmt_200, 0 };
    static cilist io___503 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___504 = { 0, 0, 0, fmt_200, 0 };
    static cilist io___506 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___507 = { 0, 0, 0, fmt_200, 0 };
    static cilist io___509 = { 0, 0, 0, 0, 0 };
    static cilist io___510 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___511 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___512 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___513 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___514 = { 0, 0, 0, fmt_200, 0 };
    static cilist io___515 = { 0, 0, 0, fmt_200, 0 };
    static cilist io___516 = { 0, 0, 0, fmt_200, 0 };
    static cilist io___517 = { 0, 0, 0, fmt_200, 0 };


/* ======================================================================= */

/*  SUBROUTINE READDT4 */

/*  READ THE HARMONICS FROM THE FILE FORT.300 */
/*  AND CONVERT THEM INTO DRIVING TERMS (SEE LHC Project Report 132) */

/*  IT IS ASSUMED THAT THE DATA ARE ALREADY CLEANED FROM THIRD ORDER */

/*  INPUT PARAMETERS: */

/*  IMIN,IMAX ENUMERATE THE DIFFERENT CASES STORED IN THE FORT.300 */
/*  NARM : NUMERO DI ARMONICHE DA ORDINARE */
/*  IR   : FLAG FOR COMPLEX OR REAL SIGNALS: */
/*         1 = INPUT SIGNAL IS REAL. */


/*  IOUT  : FORTRAN UNIT OF THE OUTPUT */

/*  AUTHOR: R.BARTOLINI 21/08/1996 */

/* ======================================================================= */
/* $OMP THREADPRIVATE(/dt/, */
/* $OMP&              i,istep, */
/* $OMP&a0013,a0040,a0301,a1003,a1012,a1021,a1030,a1120, */
/* $OMP&a1201,a1210,a1300,a2002,a2011,a2020,a2101,a3001,a3010,a4000,aaux, */
/* $OMP&aauy,c0013,c0040,c1003,c1012,c1021,c1030,c1120,c1201,c1210,c1300, */
/* $OMP&c2002,c2011,c2020,c3001,c3010,c4000,f0013,f0040,f1003,f1012, */
/* $OMP&f1021,f1030,f1120,f1201,f1210,f1300,f2002,f2011,f2020,f3001,f3010, */
/* $OMP&f4000,faux,fauy,fx,fy,pi,px,py,s0013,s0040,s1003,s1012,s1021, */
/* $OMP&s1030,s1120,s1201,s1210,s1300,s2002,s2011,s2020,s3001,s3010,s4000, */
/* $OMP&tx,ty,y1,y2, */
/* $OMP&z1012,z1021,z2011,z2101,z2110,z3100,zfli,zline) */
    pi = atan(1.) * 4;
    if (*imin <= *imax) {
	istep = 1;
    } else {
	istep = -1;
    }
    io___390.ciunit = *iout;
    s_wsle(&io___390);
    e_wsle();
    io___391.ciunit = *iout;
    s_wsle(&io___391);
    do_lio(&c__9, &c__1, "FOURTH ORDER CONJUGATING FUNCTION COEFFICIENTS", (
	    ftnlen)46);
    e_wsle();
    io___392.ciunit = *iout;
    s_wsle(&io___392);
    e_wsle();
    io___393.ciunit = *iout;
    s_wsfe(&io___393);
    do_fio(&c__1, "jklm          Amplitude              Phase", (ftnlen)42);
    do_fio(&c__1, "           Cos             Sin", (ftnlen)30);
    e_wsfe();
    io___394.ciunit = *iout;
    s_wsle(&io___394);
    e_wsle();
    i__1 = *imax;
    i__2 = istep;
    for (i__ = *imin; i__2 < 0 ? i__ >= i__1 : i__ <= i__1; i__ += i__2) {
/* tune lines */
	dt_1.dtpx[i__ - 1] = 0.;
	dt_1.dtfx[i__ - 1] = 0.;
	dt_1.dttx[i__ - 1] = 0.;
	readres_(imin, &i__, &c__1, &c__0, &c__0, narm, idam, &c__1, &c__0);
	tx[i__ - 1] = dt_1.dttx[i__ - 1];
	px[i__ - 1] = dt_1.dtpx[i__ - 1];
	fx[i__ - 1] = dt_1.dtfx[i__ - 1];
	if (*idam >= 2) {
	    dt_1.dtpx[i__ - 1] = 0.;
	    dt_1.dtfx[i__ - 1] = 0.;
	    dt_1.dttx[i__ - 1] = 0.;
	    readres_(imin, &i__, &c__0, &c__1, &c__0, narm, idam, &c__2, &
		    c__0);
	    ty[i__ - 1] = dt_1.dttx[i__ - 1];
	    py[i__ - 1] = dt_1.dtpx[i__ - 1];
	    fy[i__ - 1] = dt_1.dtfx[i__ - 1];
	}
/* CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC */
/* One dimensional resonances horizontal C */
/* CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC */
/* -3,0 line and h4000 */
	dt_1.dtpx[i__ - 1] = 0.;
	dt_1.dtfx[i__ - 1] = 0.;
	dt_1.dttx[i__ - 1] = 0.;
	readres_(imin, &i__, &c_n3, &c__0, &c__0, narm, idam, &c__1, &c__0);
/* Computing 3rd power */
	d__1 = px[i__ - 1];
	a4000 = dt_1.dtpx[i__ - 1] / 2. / 4. / (d__1 * (d__1 * d__1));
	f4000 = dt_1.dtfx[i__ - 1] - fx[i__ - 1] + 90.;
	c4000 = a4000 * cos(f4000 / 180 * pi);
	s4000 = a4000 * sin(f4000 / 180 * pi);
/* 3,0 line and h1300 */
	dt_1.dtpx[i__ - 1] = 0.;
	dt_1.dtfx[i__ - 1] = 0.;
	dt_1.dttx[i__ - 1] = 0.;
	readres_(imin, &i__, &c__3, &c__0, &c__0, narm, idam, &c__1, &c__0);
/* Computing 3rd power */
	d__1 = px[i__ - 1];
	a1300 = dt_1.dtpx[i__ - 1] / 2. / (d__1 * (d__1 * d__1));
	f1300 = dt_1.dtfx[i__ - 1] - fx[i__ - 1] + 90.;
	c1300 = a1300 * cos(f1300 / 180 * pi);
	s1300 = a1300 * sin(f1300 / 180 * pi);
/* stores this data for eventual subresonance calculation */
	aaux[i__ - 1] = a1300;
	faux[i__ - 1] = f1300;
/* other lines in case of 4D motion */
	if (*idam > 1) {
/* CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC */
/* One dimensional vertical resonances (vertical motion needed) C */
/* CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC */
/* 0,-3 line and h0040 */
	    dt_1.dtpx[i__ - 1] = 0.;
	    dt_1.dtfx[i__ - 1] = 0.;
	    dt_1.dttx[i__ - 1] = 0.;
	    readres_(imin, &i__, &c__0, &c_n3, &c__0, narm, idam, &c__2, &
		    c__0);
/* Computing 3rd power */
	    d__1 = py[i__ - 1];
	    a0040 = dt_1.dtpx[i__ - 1] / 2. / 4. / (d__1 * (d__1 * d__1));
	    f0040 = dt_1.dtfx[i__ - 1] - fy[i__ - 1] + 90.;
	    c0040 = a0040 * cos(f0040 / 180 * pi);
	    s0040 = a0040 * sin(f0040 / 180 * pi);
/* 0,3 line and h0013 */
	    dt_1.dtpx[i__ - 1] = 0.;
	    dt_1.dtfx[i__ - 1] = 0.;
	    dt_1.dttx[i__ - 1] = 0.;
	    readres_(imin, &i__, &c__0, &c__3, &c__0, narm, idam, &c__2, &
		    c__0);
/* Computing 3rd power */
	    d__1 = py[i__ - 1];
	    a0013 = dt_1.dtpx[i__ - 1] / 2. / (d__1 * (d__1 * d__1));
	    f0013 = dt_1.dtfx[i__ - 1] - fy[i__ - 1] + 90.;
	    c0013 = a0013 * cos(f0013 / 180 * pi);
	    s0013 = a0013 * sin(f0013 / 180 * pi);
/* stores this data for eventual subresonance calculation */
	    aauy[i__ - 1] = a0013;
	    fauy[i__ - 1] = f0013;
/* CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC */
/* Normal resonances from horizontal motion C */
/* CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC */
/* -1,-2 line and h2020 */
	    dt_1.dtpx[i__ - 1] = 0.;
	    dt_1.dtfx[i__ - 1] = 0.;
	    dt_1.dttx[i__ - 1] = 0.;
	    readres_(imin, &i__, &c_n1, &c_n2, &c__0, narm, idam, &c__1, &
		    c__0);
/* Computing 2nd power */
	    d__1 = py[i__ - 1];
	    a2020 = dt_1.dtpx[i__ - 1] / 2. / 2. / px[i__ - 1] / (d__1 * d__1)
		    ;
	    f2020 = dt_1.dtfx[i__ - 1] - fx[i__ - 1] + 90.;
	    c2020 = a2020 * cos(f2020 / 180 * pi);
	    s2020 = a2020 * sin(f2020 / 180 * pi);
/* -1,2 line and h2002 */
	    dt_1.dtpx[i__ - 1] = 0.;
	    dt_1.dtfx[i__ - 1] = 0.;
	    dt_1.dttx[i__ - 1] = 0.;
	    readres_(imin, &i__, &c_n1, &c__2, &c__0, narm, idam, &c__1, &
		    c__0);
/* Computing 2nd power */
	    d__1 = py[i__ - 1];
	    a2002 = dt_1.dtpx[i__ - 1] / 2. / 2. / px[i__ - 1] / (d__1 * d__1)
		    ;
	    f2002 = dt_1.dtfx[i__ - 1] - fx[i__ - 1] + 90.;
	    c2002 = a2002 * cos(f2002 / 180 * pi);
	    s2002 = a2002 * sin(f2002 / 180 * pi);
/* 1,-2 line and h1120 */
	    dt_1.dtpx[i__ - 1] = 0.;
	    dt_1.dtfx[i__ - 1] = 0.;
	    dt_1.dttx[i__ - 1] = 0.;
	    readres_(imin, &i__, &c__1, &c_n2, &c__0, narm, idam, &c__1, &
		    c__0);
/* Computing 2nd power */
	    d__1 = py[i__ - 1];
	    a1120 = dt_1.dtpx[i__ - 1] / 2. / px[i__ - 1] / (d__1 * d__1);
	    f1120 = dt_1.dtfx[i__ - 1] - fx[i__ - 1] + 90.;
	    c1120 = a1120 * cos(f1120 / 180 * pi);
	    s1120 = a1120 * sin(f1120 / 180 * pi);
/* -1,0 line and h2011 --subresonance: h3100 needed--- */
	    dt_1.dtpx[i__ - 1] = 0.;
	    dt_1.dtfx[i__ - 1] = 0.;
	    dt_1.dttx[i__ - 1] = 0.;
	    readres_(imin, &i__, &c_n1, &c__0, &c__0, narm, idam, &c__1, &
		    c__0);
	    i__3 = i__ - 1;
	    d__1 = dt_1.dtfx[i__ - 1] / 180 * pi;
	    z__3.r = 0., z__3.i = d__1;
	    z_exp(&z__2, &z__3);
	    z__1.r = dt_1.dtpx[i__3] * z__2.r, z__1.i = dt_1.dtpx[i__3] * 
		    z__2.i;
	    zline.r = z__1.r, zline.i = z__1.i;
/* .......rebulding the contribution to the (-1,0) from h3100 */
/* Computing 3rd power */
	    d__2 = px[i__ - 1];
	    d__1 = d__2 * (d__2 * d__2) * 6.;
	    z__1.r = d__1 * 0., z__1.i = d__1 * -1.;
	    zfli.r = z__1.r, zfli.i = z__1.i;
	    i__3 = i__ - 1;
	    d__1 = -faux[i__ - 1] / 180 * pi;
	    z__4.r = 0., z__4.i = d__1;
	    z_exp(&z__3, &z__4);
	    z__2.r = aaux[i__3] * z__3.r, z__2.i = aaux[i__3] * z__3.i;
	    z__1.r = z__2.r * zfli.r - z__2.i * zfli.i, z__1.i = z__2.r * 
		    zfli.i + z__2.i * zfli.r;
	    z3100.r = z__1.r, z3100.i = z__1.i;
/* .......subtracting the contribution from h3100 to the (-1,0) */
	    z__1.r = zline.r - z3100.r, z__1.i = zline.i - z3100.i;
	    z2011.r = z__1.r, z2011.i = z__1.i;
/* .......building h2011 from z2011 */
/* Computing 2nd power */
	    d__1 = py[i__ - 1];
	    a2011 = z_abs(&z2011) / 2. / 2. / px[i__ - 1] / (d__1 * d__1);
	    y1 = z2011.r;
	    y2 = d_imag(&z2011);
	    f2011 = atan2(y2, y1) * 180 / pi - fx[i__ - 1] + 90.;
	    c2011 = a2011 * cos(f2011 / 180 * pi);
	    s2011 = a2011 * sin(f2011 / 180 * pi);
/* CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC */
/* Skew resonances from horizontal motion C */
/* CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC */
/* -2,-1 line and h3010 */
	    dt_1.dtpx[i__ - 1] = 0.;
	    dt_1.dtfx[i__ - 1] = 0.;
	    dt_1.dttx[i__ - 1] = 0.;
	    readres_(imin, &i__, &c_n2, &c_n1, &c__0, narm, idam, &c__1, &
		    c__0);
/* Computing 2nd power */
	    d__1 = px[i__ - 1];
	    a3010 = dt_1.dtpx[i__ - 1] / 2. / 3. / (d__1 * d__1) / py[i__ - 1]
		    ;
	    f3010 = dt_1.dtfx[i__ - 1] - fx[i__ - 1] + 90.;
	    c3010 = a3010 * cos(f3010 / 180 * pi);
	    s3010 = a3010 * sin(f3010 / 180 * pi);
/*  2,1 line and h1201 */
	    dt_1.dtpx[i__ - 1] = 0.;
	    dt_1.dtfx[i__ - 1] = 0.;
	    dt_1.dttx[i__ - 1] = 0.;
	    readres_(imin, &i__, &c__2, &c__1, &c__0, narm, idam, &c__1, &
		    c__0);
/* Computing 2nd power */
	    d__1 = px[i__ - 1];
	    a1201 = dt_1.dtpx[i__ - 1] / 2. / (d__1 * d__1) / py[i__ - 1];
	    f1201 = dt_1.dtfx[i__ - 1] - fx[i__ - 1] + 90.;
	    c1201 = a1201 * cos(f1201 / 180 * pi);
	    s1201 = a1201 * sin(f1201 / 180 * pi);
/*  2,-1 line and h1210 */
	    dt_1.dtpx[i__ - 1] = 0.;
	    dt_1.dtfx[i__ - 1] = 0.;
	    dt_1.dttx[i__ - 1] = 0.;
	    readres_(imin, &i__, &c__2, &c_n1, &c__0, narm, idam, &c__1, &
		    c__0);
/* Computing 2nd power */
	    d__1 = px[i__ - 1];
	    a1210 = dt_1.dtpx[i__ - 1] / 2. / (d__1 * d__1) / py[i__ - 1];
	    f1210 = dt_1.dtfx[i__ - 1] - fx[i__ - 1] + 90.;
	    c1210 = a1210 * cos(f1210 / 180 * pi);
	    s1210 = a1210 * sin(f1210 / 180 * pi);
/* -2,1 line and h3001 */
	    dt_1.dtpx[i__ - 1] = 0.;
	    dt_1.dtfx[i__ - 1] = 0.;
	    dt_1.dttx[i__ - 1] = 0.;
	    readres_(imin, &i__, &c_n2, &c__1, &c__0, narm, idam, &c__1, &
		    c__0);
/* Computing 2nd power */
	    d__1 = px[i__ - 1];
	    a3001 = dt_1.dtpx[i__ - 1] / 2. / 3. / (d__1 * d__1) / py[i__ - 1]
		    ;
	    f3001 = dt_1.dtfx[i__ - 1] - fx[i__ - 1] + 90.;
	    c3001 = a3001 * cos(f3001 / 180 * pi);
	    s3001 = a3001 * sin(f3001 / 180 * pi);
/* 0,-3 line and h1030 */
	    dt_1.dtpx[i__ - 1] = 0.;
	    dt_1.dtfx[i__ - 1] = 0.;
	    dt_1.dttx[i__ - 1] = 0.;
	    readres_(imin, &i__, &c__0, &c_n3, &c__0, narm, idam, &c__1, &
		    c__0);
/* Computing 3rd power */
	    d__1 = py[i__ - 1];
	    a1030 = dt_1.dtpx[i__ - 1] / 2. / (d__1 * (d__1 * d__1));
	    f1030 = dt_1.dtfx[i__ - 1] - fx[i__ - 1] + 90.;
	    c1030 = a1030 * cos(f1030 / 180 * pi);
	    s1030 = a1030 * sin(f1030 / 180 * pi);
/* 0,-1 line and h1021 --subresonance h2110 needed-- */
	    dt_1.dtpx[i__ - 1] = 0.;
	    dt_1.dtfx[i__ - 1] = 0.;
	    dt_1.dttx[i__ - 1] = 0.;
	    readres_(imin, &i__, &c__0, &c_n1, &c__0, narm, idam, &c__1, &
		    c__0);
	    i__3 = i__ - 1;
	    d__1 = dt_1.dtfx[i__ - 1] / 180 * pi;
	    z__3.r = 0., z__3.i = d__1;
	    z_exp(&z__2, &z__3);
	    z__1.r = dt_1.dtpx[i__3] * z__2.r, z__1.i = dt_1.dtpx[i__3] * 
		    z__2.i;
	    zline.r = z__1.r, zline.i = z__1.i;
/* .......rebulding the contribution to the (0,-1) from h2110 */
/* Computing 2nd power */
	    d__2 = px[i__ - 1];
	    d__1 = d__2 * d__2 * 4. * py[i__ - 1];
	    z__1.r = d__1 * 0., z__1.i = d__1 * -1.;
	    zfli.r = z__1.r, zfli.i = z__1.i;
	    d__1 = -f1201 / 180 * pi;
	    z__4.r = 0., z__4.i = d__1;
	    z_exp(&z__3, &z__4);
	    z__2.r = a1201 * z__3.r, z__2.i = a1201 * z__3.i;
	    z__1.r = z__2.r * zfli.r - z__2.i * zfli.i, z__1.i = z__2.r * 
		    zfli.i + z__2.i * zfli.r;
	    z2110.r = z__1.r, z2110.i = z__1.i;
/* .......subtracting the contribution from h2110 to the (0,-1) */
	    z__1.r = zline.r - z2110.r, z__1.i = zline.i - z2110.i;
	    z1021.r = z__1.r, z1021.i = z__1.i;
/* .......building h1021 from z1021 */
/* Computing 3rd power */
	    d__1 = py[i__ - 1];
	    a1021 = z_abs(&z1021) / 2. / (d__1 * (d__1 * d__1));
	    y1 = z1021.r;
	    y2 = d_imag(&z1021);
	    f1021 = atan2(y2, y1) * 180 / pi - fx[i__ - 1] + 90.;
	    c1021 = a1021 * cos(f1021 / 180 * pi);
	    s1021 = a1021 * sin(f1021 / 180 * pi);
/* 0,1 line and h1012 --subresonance h2101 needed-- */
	    dt_1.dtpx[i__ - 1] = 0.;
	    dt_1.dtfx[i__ - 1] = 0.;
	    dt_1.dttx[i__ - 1] = 0.;
	    readres_(imin, &i__, &c__0, &c__1, &c__0, narm, idam, &c__1, &
		    c__0);
	    i__3 = i__ - 1;
	    d__1 = dt_1.dtfx[i__ - 1] / 180 * pi;
	    z__3.r = 0., z__3.i = d__1;
	    z_exp(&z__2, &z__3);
	    z__1.r = dt_1.dtpx[i__3] * z__2.r, z__1.i = dt_1.dtpx[i__3] * 
		    z__2.i;
	    zline.r = z__1.r, zline.i = z__1.i;
/* .......rebulding the contribution to the (0,1) from h2101 */
/* Computing 2nd power */
	    d__2 = px[i__ - 1];
	    d__1 = d__2 * d__2 * 4. * py[i__ - 1];
	    z__1.r = d__1 * 0., z__1.i = d__1 * -1.;
	    zfli.r = z__1.r, zfli.i = z__1.i;
	    d__1 = -f1210 / 180 * pi;
	    z__4.r = 0., z__4.i = d__1;
	    z_exp(&z__3, &z__4);
	    z__2.r = a1210 * z__3.r, z__2.i = a1210 * z__3.i;
	    z__1.r = z__2.r * zfli.r - z__2.i * zfli.i, z__1.i = z__2.r * 
		    zfli.i + z__2.i * zfli.r;
	    z2101.r = z__1.r, z2101.i = z__1.i;
/* .......subtracting the contribution from h2101 to the (0,1) */
	    z__1.r = zline.r - z2101.r, z__1.i = zline.i - z2101.i;
	    z1012.r = z__1.r, z1012.i = z__1.i;
/* .......building h1012 from z1012 */
/* Computing 3rd power */
	    d__1 = py[i__ - 1];
	    a1012 = z_abs(&z1012) / 2. / (d__1 * (d__1 * d__1));
	    y1 = z1012.r;
	    y2 = d_imag(&z1012);
	    f1012 = atan2(y2, y1) * 180 / pi - fx[i__ - 1] + 90.;
	    c1012 = a1012 * cos(f1012 / 180 * pi);
	    s1012 = a1012 * sin(f1012 / 180 * pi);
/* 0,3 line and h1003 */
	    dt_1.dtpx[i__ - 1] = 0.;
	    dt_1.dtfx[i__ - 1] = 0.;
	    dt_1.dttx[i__ - 1] = 0.;
	    readres_(imin, &i__, &c__0, &c__3, &c__0, narm, idam, &c__1, &
		    c__0);
/* Computing 3rd power */
	    d__1 = py[i__ - 1];
	    a1003 = dt_1.dtpx[i__ - 1] / 2. / (d__1 * (d__1 * d__1));
	    f1003 = dt_1.dtfx[i__ - 1] - fx[i__ - 1] + 90.;
	    c1003 = a1003 * cos(f1003 / 180 * pi);
	    s1003 = a1003 * sin(f1003 / 180 * pi);
	}
	io___480.ciunit = *iout;
	s_wsfe(&io___480);
	do_fio(&c__1, "4000", (ftnlen)4);
	do_fio(&c__1, (char *)&a4000, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&f4000, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&c4000, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&s4000, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___481.ciunit = *iout;
	s_wsfe(&io___481);
	do_fio(&c__1, "3100", (ftnlen)4);
	do_fio(&c__1, (char *)&a1300, (ftnlen)sizeof(doublereal));
	d__1 = -f1300;
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___482.ciunit = *iout;
	s_wsfe(&io___482);
	do_fio(&c__1, "1300", (ftnlen)4);
	do_fio(&c__1, (char *)&a1300, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&f1300, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&c1300, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&s1300, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___483.ciunit = *iout;
	s_wsfe(&io___483);
	do_fio(&c__1, "0400", (ftnlen)4);
	do_fio(&c__1, (char *)&a4000, (ftnlen)sizeof(doublereal));
	d__1 = -f4000;
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___484.ciunit = *iout;
	s_wsle(&io___484);
	e_wsle();
	io___485.ciunit = *iout;
	s_wsfe(&io___485);
	do_fio(&c__1, "2020", (ftnlen)4);
	do_fio(&c__1, (char *)&a2020, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&f2020, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&c2020, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&s2020, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___486.ciunit = *iout;
	s_wsfe(&io___486);
	do_fio(&c__1, "2011", (ftnlen)4);
	do_fio(&c__1, (char *)&a2011, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&f2011, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&c2011, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&s2011, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___487.ciunit = *iout;
	s_wsfe(&io___487);
	do_fio(&c__1, "2002", (ftnlen)4);
	do_fio(&c__1, (char *)&a2002, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&f2002, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&c2002, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&s2002, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___488.ciunit = *iout;
	s_wsfe(&io___488);
	do_fio(&c__1, "1120", (ftnlen)4);
	do_fio(&c__1, (char *)&a1120, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&f1120, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&c1120, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&s1120, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___489.ciunit = *iout;
	s_wsfe(&io___489);
	do_fio(&c__1, "1102", (ftnlen)4);
	do_fio(&c__1, (char *)&a1120, (ftnlen)sizeof(doublereal));
	d__1 = -f1120;
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___490.ciunit = *iout;
	s_wsfe(&io___490);
	do_fio(&c__1, "0220", (ftnlen)4);
	do_fio(&c__1, (char *)&a2002, (ftnlen)sizeof(doublereal));
	d__1 = -f2002;
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___491.ciunit = *iout;
	s_wsfe(&io___491);
	do_fio(&c__1, "0211", (ftnlen)4);
	do_fio(&c__1, (char *)&a2011, (ftnlen)sizeof(doublereal));
	d__1 = -f2011;
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___492.ciunit = *iout;
	s_wsfe(&io___492);
	do_fio(&c__1, "0202", (ftnlen)4);
	do_fio(&c__1, (char *)&a2020, (ftnlen)sizeof(doublereal));
	d__1 = -f2020;
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___493.ciunit = *iout;
	s_wsle(&io___493);
	e_wsle();
	io___494.ciunit = *iout;
	s_wsfe(&io___494);
	do_fio(&c__1, "0040", (ftnlen)4);
	do_fio(&c__1, (char *)&a0040, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&f0040, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&c0040, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&s0040, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___495.ciunit = *iout;
	s_wsfe(&io___495);
	do_fio(&c__1, "0031", (ftnlen)4);
	do_fio(&c__1, (char *)&a0013, (ftnlen)sizeof(doublereal));
	d__1 = -f0013;
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___496.ciunit = *iout;
	s_wsfe(&io___496);
	do_fio(&c__1, "0013", (ftnlen)4);
	do_fio(&c__1, (char *)&a0013, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&f0013, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&c0013, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&s0013, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___497.ciunit = *iout;
	s_wsfe(&io___497);
	do_fio(&c__1, "0004", (ftnlen)4);
	do_fio(&c__1, (char *)&a0040, (ftnlen)sizeof(doublereal));
	d__1 = -f0040;
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___498.ciunit = *iout;
	s_wsle(&io___498);
	e_wsle();
	io___499.ciunit = *iout;
	s_wsfe(&io___499);
	do_fio(&c__1, "3010", (ftnlen)4);
	do_fio(&c__1, (char *)&a3010, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&f3010, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&c3010, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&s3010, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___500.ciunit = *iout;
	s_wsfe(&io___500);
	do_fio(&c__1, "2110", (ftnlen)4);
	do_fio(&c__1, (char *)&a1201, (ftnlen)sizeof(doublereal));
	d__1 = -f1201;
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___501.ciunit = *iout;
	s_wsfe(&io___501);
	do_fio(&c__1, "1210", (ftnlen)4);
	do_fio(&c__1, (char *)&a1210, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&f1210, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&c1210, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&s1210, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___502.ciunit = *iout;
	s_wsfe(&io___502);
	do_fio(&c__1, "0310", (ftnlen)4);
	do_fio(&c__1, (char *)&a3001, (ftnlen)sizeof(doublereal));
	d__1 = -f3001;
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___503.ciunit = *iout;
	s_wsfe(&io___503);
	do_fio(&c__1, "3001", (ftnlen)4);
	do_fio(&c__1, (char *)&a3001, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&f3001, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&c3001, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&s3001, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___504.ciunit = *iout;
	s_wsfe(&io___504);
	do_fio(&c__1, "2101", (ftnlen)4);
	do_fio(&c__1, (char *)&a2101, (ftnlen)sizeof(doublereal));
	d__1 = -f1210;
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___506.ciunit = *iout;
	s_wsfe(&io___506);
	do_fio(&c__1, "1201", (ftnlen)4);
	do_fio(&c__1, (char *)&a1201, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&f1201, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&c1201, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&s1201, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___507.ciunit = *iout;
	s_wsfe(&io___507);
	do_fio(&c__1, "0301", (ftnlen)4);
	do_fio(&c__1, (char *)&a0301, (ftnlen)sizeof(doublereal));
	d__1 = -f3010;
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___509.ciunit = *iout;
	s_wsle(&io___509);
	e_wsle();
	io___510.ciunit = *iout;
	s_wsfe(&io___510);
	do_fio(&c__1, "1030", (ftnlen)4);
	do_fio(&c__1, (char *)&a1030, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&f1030, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&c1030, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&s1030, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___511.ciunit = *iout;
	s_wsfe(&io___511);
	do_fio(&c__1, "1021", (ftnlen)4);
	do_fio(&c__1, (char *)&a1021, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&f1021, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&c1021, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&s1021, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___512.ciunit = *iout;
	s_wsfe(&io___512);
	do_fio(&c__1, "1012", (ftnlen)4);
	do_fio(&c__1, (char *)&a1012, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&f1012, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&c1012, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&s1012, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___513.ciunit = *iout;
	s_wsfe(&io___513);
	do_fio(&c__1, "1003", (ftnlen)4);
	do_fio(&c__1, (char *)&a1003, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&f1003, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&c1003, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&s1003, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___514.ciunit = *iout;
	s_wsfe(&io___514);
	do_fio(&c__1, "0103", (ftnlen)4);
	do_fio(&c__1, (char *)&a1030, (ftnlen)sizeof(doublereal));
	d__1 = -f1030;
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___515.ciunit = *iout;
	s_wsfe(&io___515);
	do_fio(&c__1, "0112", (ftnlen)4);
	do_fio(&c__1, (char *)&a1021, (ftnlen)sizeof(doublereal));
	d__1 = -f1021;
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___516.ciunit = *iout;
	s_wsfe(&io___516);
	do_fio(&c__1, "0121", (ftnlen)4);
	do_fio(&c__1, (char *)&a1012, (ftnlen)sizeof(doublereal));
	d__1 = -f1012;
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___517.ciunit = *iout;
	s_wsfe(&io___517);
	do_fio(&c__1, "0130", (ftnlen)4);
	do_fio(&c__1, (char *)&a1003, (ftnlen)sizeof(doublereal));
	d__1 = -f1003;
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    return 0;
} /* readdt4_ */

/* Subroutine */ int readsme_(integer *imin, integer *imax, integer *narm, 
	integer *idam, integer *idamx, integer *iusm)
{
    /* Builtin functions */
    double atan(doublereal);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static doublereal pi;
    static char ch1[200];
    static integer istep;

/* ======================================================================= */

/*  READ THE HARMONICS FROM FORT.300 */
/*  GIVES THE SMEAR AS A QUALITY FACTOR FOR THE DIFFERENT CASES */

/*  INPUT PARAMETERS: */

/*  NARM : NUMERO DI ARMONICHE DA ORDINARE */
/*  IR   : FLAG FOR COMPLEX OR REAL SIGNALS: */
/*         1 = INPUT SIGNAL IS REAL. */
/*         IF THE SIGNAL IS REAL IT IS TRASPOSED IN [0,0.5] */

/*  N.B. :  THE STRENGTH OF NEXT TO LEADING LINES ARE NORMALIZED AT THE */
/*          TUNE STRENGTH. */
/*  MIND :  THE ARRAYS TX,TY,TZ ARE USED IN ORDER NOT TO CHANGE */
/*          THE ARRAYS TUNEX,TUNEY,TUNEZ. */

/*  IOU  : FORTRAN UNIT OF THE OUTPUT */

/*  AUTHOR: R.BARTOLINI 21/08/1996 */

/* ======================================================================= */
/* $OMP THREADPRIVATE(i,istep,j,k,ki,l,m,n,ni, */
/* $OMP&ex,fx,pi,px,qsme,tx,ch,ch1) */
    pi = atan(1.) * 4;
    s_copy(ch1, " ", (ftnlen)200, (ftnlen)1);
    if (*imin <= *imax) {
	istep = 1;
    } else {
	istep = -1;
    }
/*      rewind(30) */
/*      do i=imin,imax,istep */
/* C        write(6,*)'ANALYZING UNIT 300 FOR SMEAR CALCULATION, CASE:',i */
/*        qsme=0d+0 */
/*        do ki=1,idam */
/* 1        read(30,'(A)',end=2) ch */
/* c Find start for each plane */
/*          if(ch(1:9).eq.' ANALYSIS') then */
/*            read(30,'()',end=2) */
/*           read(30,'()',end=2) */
/*           read(30,'()',end=2) */
/*           read(30,'()',end=2) */
/*           do ni=1,narm */
/*              read(30,'(A)',end=2) ch */
/*              if(ch.eq.ch1) goto 3 */
/*              read(ch,100,end=2)n,tx(n),px,fx,ex,l,m,k,j */
/*              if(ki.eq.idamx) then */
/*                if(ni.ge.2) then */
/*                  qsme=qsme+px */
/*                endif */
/*              endif */
/*            enddo */
/*          else */
/*            goto 1 */
/*          endif */
/*        enddo */
/* 3      continue */
/*        write(iusm,*)i,qsme */
/*      enddo */
/* 2    continue */
/*      rewind(30) */

/* 100   format(i3,1x,f19.16,2(1x,e18.12),1x,e17.11,:,4(1x,i3)) */
    return 0;
} /* readsme_ */

/* Subroutine */ int readinv_(integer *imin, integer *imax, integer *narm, 
	integer *idam, integer *idamx, integer *iinv)
{
    /* Builtin functions */
    double atan(doublereal);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, k[900]	/* was [3][300] */, l[900]	/* was [3][
	    300] */, m[900]	/* was [3][300] */, ii;
    static doublereal pi, px[900]	/* was [3][300] */;
    static char ch1[200];
    static integer istep;

/* ======================================================================= */

/*  READ THE HARMONICS FROM FORT.300 */
/*  GIVES THE INVARIANTS FOR THE 3 PLANES */

/*  INPUT PARAMETERS: */

/*  IMIN : MIN */
/*  IMAX : &MAX NUMBER OF CASES */

/*  NARM : NUMERO DI ARMONICHE DA ORDINARE */

/*  IDAM : NUMBER OF PLANES */

/*  IDAMX: DUMMY */

/*  IINV : OUTPUT UNIT */

/*  THEORY: A.BAZZANI, L.BONGINI, G.TURCHETTI, AIP 329, PAGE 120 */
/*  AUTHOR: R.BARTOLINI/F.Schmidt 14/08/1997 */
/*  last change 22/09/1997 */

/* ======================================================================= */
/* $OMP THREADPRIVATE(i,ii,istep,j,k,ki,kii,kkini,l,lkini,m,mkini,n,ni, */
/* $OMP&ex,fx,pi,psinv,px,pxinv,pyinv,tx,ch,ch1) */
    pi = atan(1.) * 4;
    s_copy(ch1, " ", (ftnlen)200, (ftnlen)1);
    if (*imin <= *imax) {
	istep = 1;
    } else {
	istep = -1;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
	for (ii = 1; ii <= 300; ++ii) {
	    l[i__ + ii * 3 - 4] = 0;
	    m[i__ + ii * 3 - 4] = 0;
	    k[i__ + ii * 3 - 4] = 0;
	}
    }
    for (i__ = 1; i__ <= 3; ++i__) {
	for (ii = 1; ii <= 300; ++ii) {
	    px[i__ + ii * 3 - 4] = 0.;
	}
    }
/*      rewind(30) */
/* c study imax-imin+1 sets of data */
/*      do i=imin,imax,istep */
/* C        write(6,*)'ANALYZING UNIT 300. INVARIANT CALCULATION, CASE:',i */
/* c loop over planes */
/*        do 3 ki=1,idam */
/* 1        read(30,'(A)',end=2) ch */
/* c Find start for each plane */
/*          if(ch(1:9).eq.' ANALYSIS') then */
/*            read(30,'()',end=2) */
/*            read(30,'()',end=2) */
/*            read(30,'()',end=2) */
/*            read(30,'()',end=2) */
/*            do 4 ni=1,narm */
/*              read(30,'(A)',end=2) ch */
/* c Detect end of data and exit to 3 to study next plane */
/*              if(ch.eq.ch1) goto 3 */
/*              lkini=0 */
/*              mkini=0 */
/*              kkini=0 */
/*              read(ch,100)n,tx,px(ki,ni),fx,ex,lkini,mkini,kkini,j */
/* c Reject new line if already present in analysed (ni-1) lines */
/*              if(ni.gt.1) then */
/*                do kii=1,ni-1 */
/*                  if(l(ki,kii).eq.lkini.and.m(ki,kii).eq.mkini.and. */
/*     &                 k(ki,kii).eq.kkini) then */
/* c true when line already exists => exit to 4 to look for new line */
/*                    l(ki,ni)=0 */
/*                    m(ki,ni)=0 */
/*                    k(ki,ni)=0 */
/*                    goto 4 */
/*                  endif */
/*                enddo */
/*              endif */
/* c set new coefficients */
/*              l(ki,ni)=lkini */
/*              m(ki,ni)=mkini */
/*              k(ki,ni)=kkini */
/* 4          continue */
/*          else */
/*            goto 1 */
/*          endif */
/* 3      continue */
/* C.......INVARIANTS CALCULATION */
/*        pxinv=0d0 */
/*        pyinv=0d0 */
/*        psinv=0d0 */
/*        do n=1,narm */
/*          pxinv=pxinv+l(1,n)*px(1,n)**2+ */
/*     &                l(2,n)*px(2,n)**2+ */
/*     &                l(3,n)*px(3,n)**2 */
/*          pyinv=pyinv+m(1,n)*px(1,n)**2+ */
/*     &                m(2,n)*px(2,n)**2+ */
/*     &                m(3,n)*px(3,n)**2 */
/*          psinv=psinv+k(1,n)*px(1,n)**2+ */
/*     &                k(2,n)*px(2,n)**2+ */
/*     &                k(3,n)*px(3,n)**2 */
/*        enddo */
/*        if(pxinv.lt.zero) then */
/* C          write(6,*)'Warning: Horizontal Invariant negative' */
/*          pxinv=zero */
/*        else */
/*          pxinv=sqrt(pxinv) */
/*        endif */
/*        if(pyinv.lt.zero) then */
/* C          write(6,*)'Warning: Vertical Invariant negative' */
/*          pyinv=zero */
/*        else */
/*          pyinv=sqrt(pyinv) */
/*        endif */
/*        if(psinv.lt.zero) then */
/* C          write(6,*)'Warning: Longitudinal Invariant negative' */
/*          psinv=zero */
/*        else */
/*          psinv=sqrt(psinv) */
/*        endif */

/*        write(iinv,'(3(1X,E20.12))')pxinv,pyinv,psinv */

/*      enddo */
/*      rewind(30) */
/* 2    continue */
/* 100   format(i3,1x,f19.16,2(1x,e18.12),1x,e17.11,:,4(1x,i3)) */
    return 0;
} /* readinv_ */

/* Subroutine */ int readric_(integer *nfile, integer *idam, integer *ntwin, 
	integer *iconv)
{
    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2;
    alist al__1;

    /* Builtin functions */
    double atan(doublereal);
    integer f_rew(alist *), s_rsue(cilist *), do_uio(integer *, char *, 
	    ftnlen), e_rsue(void), s_wsfe(cilist *), do_fio(integer *, char *,
	     ftnlen), e_wsfe(void);

    /* Local variables */
    static doublereal b, c__, d__, e, f, g, h__;
    static integer i__, j;
    static doublereal p, t[36]	/* was [6][6] */, c1, d1, e1, f1, g1, h1, p1;
    static integer ia;
    static doublereal ta[36]	/* was [6][6] */, pi;
    static integer iq, jq;
    static doublereal clo[3], qwc[3], di0x, di0z, clop[3];
    extern /* Subroutine */ int dinv_(integer *, doublereal *, integer *, 
	    integer *, integer *);
    static doublereal dnms;
    static integer numl;
    static doublereal txyz[6], xyzv[6], dip0x, dip0z;
    static integer its6d;
    static doublereal dizu0;
    static char cdate[8];
    static doublereal dmmac;
    static integer icode, ilapa, ifipa;
    static char ctime[8];
    static integer itopa;
    static doublereal tasum, dummy;
    static integer nfile0, nfile1;
    static char prgram[8];
    static doublereal dnumlr;
    static integer nerror, rdummy;
    static char sixtit[80], comment[80];

    /* Fortran I/O blocks */
    static cilist io___534 = { 0, 0, 0, 0, 0 };
    static cilist io___564 = { 0, 0, 1, 0, 0 };
    static cilist io___574 = { 0, 0, 1, 0, 0 };
    static cilist io___586 = { 0, 0, 0, "(6(G21.15,1X))", 0 };
    static cilist io___587 = { 0, 0, 0, "(6(G21.15,1X))", 0 };
    static cilist io___588 = { 0, 0, 0, "(6(G21.15,1X))", 0 };


/* ======================================================================= */

/* SUBROUTINE READRIC */

/* GIVEN A SIXTRACK BINARY FILE IT CONVERTS IT INTO ONE OR TWO ASCII */
/* ACCORDING TO NTWIN. */

/* NFILE IS THE UNIT OF THE FORT.NFILE TO BE PROCESSED */

/* THE OUTPUT ARE ALWAYS IN FORT.91 AND FORT.92 */

/* N.B.: NTWIN IS AN OUTPUT PARAMETER AND THE NUMBER OF TURN */
/*       IS AUTOMATICALLY DETERMINED FROM READING THE WHOLE FILE. */

/* ======================================================================= */
/* $OMP THREADPRIVATE(i,ia,icode,ifipa,ilapa,iq,itopa,its6d,j,jq, */
/* $OMP&              nerror,nfile0,nfile1,numl,rdummy, */
/* $OMP&b,c,c1,clo,clop,d,d1,dizu0,di0x,di0z,dip0x,dip0z, */
/* $OMP&dmmac,dnms,dnumlr,dummy,e,e1,f,f1,g,g1,h,h1,p,pi,p1,qwc, */
/* $OMP&t,ta,tasum,txyz,xyzv, */
/* $OMP&sixtit,comment,cdate,ctime,prgram) */
    pi = atan(1.) * 4.;
    dummy = 0.;
/* --------------------------------------------------------------------- */
    nfile0 = 91;
    nfile1 = 92;
    al__1.aerr = 0;
    al__1.aunit = *nfile;
    f_rew(&al__1);
    al__1.aerr = 0;
    al__1.aunit = nfile0;
    f_rew(&al__1);
    al__1.aerr = 0;
    al__1.aunit = nfile1;
    f_rew(&al__1);
    io___534.ciunit = *nfile;
    s_rsue(&io___534);
    do_uio(&c__1, sixtit, (ftnlen)80);
    do_uio(&c__1, comment, (ftnlen)80);
    do_uio(&c__1, cdate, (ftnlen)8);
    do_uio(&c__1, ctime, (ftnlen)8);
    do_uio(&c__1, prgram, (ftnlen)8);
    do_uio(&c__1, (char *)&ifipa, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&ilapa, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&itopa, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&icode, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&numl, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&qwc[0], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&qwc[1], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&qwc[2], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&clo[0], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&clop[0], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&clo[1], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&clop[1], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&clo[2], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&clop[2], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&di0x, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dip0x, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&di0z, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dip0z, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[0], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[6], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[12], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[18], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[24], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[30], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[1], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[7], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[13], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[19], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[25], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[31], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[2], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[8], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[14], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[20], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[26], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[32], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[3], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[9], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[15], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[21], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[27], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[33], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[4], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[10], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[16], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[22], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[28], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[34], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[5], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[11], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[17], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[23], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[29], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[35], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dmmac, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dnms, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dizu0, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dnumlr, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    e_rsue();
/* --REPAIR PARTIAL OR TOTAL INCOMPLETE TRANSFER MATRIX */
    if (abs(ta[0]) <= 1e-17 && abs(ta[7]) <= 1e-17) {
	ta[0] = 1.;
	ta[7] = 1.;
    }
    if (abs(ta[14]) <= 1e-17 && abs(ta[21]) <= 1e-17) {
	ta[14] = 1.;
	ta[21] = 1.;
    }
    if (abs(ta[28]) <= 1e-17 && abs(ta[35]) <= 1e-17) {
	ta[28] = 1.;
	ta[35] = 1.;
    }
    its6d = 0;
/* --Convert if requested */
    if (*iconv != 1) {
	for (i__ = 1; i__ <= 6; ++i__) {
	    for (j = 1; j <= 6; ++j) {
		if (i__ != j) {
		    ta[i__ + j * 6 - 7] = 0.;
		} else {
		    ta[i__ + j * 6 - 7] = 1.;
		}
	    }
	}
    }
/* --TEST IF TRANSFER MATRIX HAS LONGITUDINAL PART */
    for (i__ = 1; i__ <= 6; ++i__) {
	tasum = tasum + (d__1 = ta[i__ + 23], abs(d__1)) + (d__2 = ta[i__ + 
		29], abs(d__2));
/* L110: */
    }
    for (i__ = 1; i__ <= 4; ++i__) {
	tasum = tasum + (d__1 = ta[i__ * 6 - 2], abs(d__1)) + (d__2 = ta[i__ *
		 6 - 1], abs(d__2));
/* L120: */
    }
    tasum += -2.;
    if (abs(tasum) >= 1e-17) {
	its6d = 1;
    }
/* --INVERT TRANSFER MATRIX */
    for (i__ = 1; i__ <= 6; ++i__) {
	for (j = 1; j <= 6; ++j) {
	    t[i__ + j * 6 - 7] = ta[j + i__ * 6 - 7];
/* L140: */
	}
/* L130: */
    }
    dinv_(&c__6, t, &c__6, &rdummy, &nerror);
/* --DETERMINE ORDER OF FREEDOM OF TRACKED CASE */
/*      IF(ICODE.EQ.1.OR.ICODE.EQ.2.OR.ICODE.EQ.4) IDAM=1 */
/*      IF(ICODE.EQ.3.OR.ICODE.EQ.5.OR.ICODE.EQ.6) IDAM=2 */
/*      IF(ICODE.EQ.7) IDAM=3 */
/* --CHECK IF 1 OR 2 SETS OF COORDINATES ARE WRITTEN */
    *ntwin = 1;
    if (ilapa != ifipa) {
	*ntwin = 2;
    }
/*      write(6,*)'ANALYZING THE BINARY SIXTRACK OUTPUT' */
    i__1 = numl + 1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (*ntwin == 1) {
	    io___564.ciunit = *nfile;
	    i__2 = s_rsue(&io___564);
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = do_uio(&c__1, (char *)&ia, (ftnlen)sizeof(integer));
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = do_uio(&c__1, (char *)&ifipa, (ftnlen)sizeof(integer));
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = do_uio(&c__1, (char *)&b, (ftnlen)sizeof(doublereal));
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = do_uio(&c__1, (char *)&c__, (ftnlen)sizeof(doublereal));
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = do_uio(&c__1, (char *)&d__, (ftnlen)sizeof(doublereal));
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = do_uio(&c__1, (char *)&e, (ftnlen)sizeof(doublereal));
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = do_uio(&c__1, (char *)&f, (ftnlen)sizeof(doublereal));
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = do_uio(&c__1, (char *)&g, (ftnlen)sizeof(doublereal));
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = do_uio(&c__1, (char *)&h__, (ftnlen)sizeof(doublereal));
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = do_uio(&c__1, (char *)&p, (ftnlen)sizeof(doublereal));
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = e_rsue();
	    if (i__2 != 0) {
		goto L999;
	    }
	}
	if (*ntwin == 2) {
	    io___574.ciunit = *nfile;
	    i__2 = s_rsue(&io___574);
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = do_uio(&c__1, (char *)&ia, (ftnlen)sizeof(integer));
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = do_uio(&c__1, (char *)&ifipa, (ftnlen)sizeof(integer));
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = do_uio(&c__1, (char *)&b, (ftnlen)sizeof(doublereal));
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = do_uio(&c__1, (char *)&c__, (ftnlen)sizeof(doublereal));
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = do_uio(&c__1, (char *)&d__, (ftnlen)sizeof(doublereal));
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = do_uio(&c__1, (char *)&e, (ftnlen)sizeof(doublereal));
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = do_uio(&c__1, (char *)&f, (ftnlen)sizeof(doublereal));
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = do_uio(&c__1, (char *)&g, (ftnlen)sizeof(doublereal));
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = do_uio(&c__1, (char *)&h__, (ftnlen)sizeof(doublereal));
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = do_uio(&c__1, (char *)&p, (ftnlen)sizeof(doublereal));
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = do_uio(&c__1, (char *)&ilapa, (ftnlen)sizeof(integer));
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = do_uio(&c__1, (char *)&b, (ftnlen)sizeof(doublereal));
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = do_uio(&c__1, (char *)&c1, (ftnlen)sizeof(doublereal));
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = do_uio(&c__1, (char *)&d1, (ftnlen)sizeof(doublereal));
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = do_uio(&c__1, (char *)&e1, (ftnlen)sizeof(doublereal));
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = do_uio(&c__1, (char *)&f1, (ftnlen)sizeof(doublereal));
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = do_uio(&c__1, (char *)&g1, (ftnlen)sizeof(doublereal));
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = do_uio(&c__1, (char *)&h1, (ftnlen)sizeof(doublereal));
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = do_uio(&c__1, (char *)&p1, (ftnlen)sizeof(doublereal));
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = e_rsue();
	    if (i__2 != 0) {
		goto L999;
	    }
	}
/* --SUBTRACT CLOSED ORBIT */
	c__ -= clo[0];
	d__ -= clop[0];
	e -= clo[1];
	f -= clop[1];
	g -= clo[2];
	h__ -= clop[2];
/* --!! SUBTRACT DISPERSION ONLY IF THE LONGITUDINAL */
/* --PART OF THE TRANSFER MATRIX HAS NOT BEEN */
/* --CALCULATED BUT THERE ARE SYNCHROTRON OSCILLATIONS */
	if (icode >= 4 && its6d == 0) {
	    c__ -= di0x * h__;
	    d__ -= dip0x * h__;
	    e -= di0z * h__;
	    f -= dip0z * h__;
	}
	xyzv[0] = c__;
	xyzv[1] = d__;
	xyzv[2] = e;
	xyzv[3] = f;
	xyzv[4] = g;
	xyzv[5] = h__;
/* --TRANSFER FIRST SET OF DATA */
	for (iq = 1; iq <= 6; ++iq) {
	    txyz[iq - 1] = 0.;
	    for (jq = 1; jq <= 6; ++jq) {
		txyz[iq - 1] += t[jq + iq * 6 - 7] * xyzv[jq - 1];
/* L170: */
	    }
/* L160: */
	}
	c__ = txyz[0];
	d__ = txyz[1];
	e = txyz[2];
	f = txyz[3];
	g = txyz[4];
/* --!!IMPORTANT THE MOMENTUM HAS A TRIVIAL SCALING!! */
	h__ = txyz[5] * 1e3;
	if (*ntwin == 2) {
	    c1 -= clo[0];
	    d1 -= clop[0];
	    e1 -= clo[1];
	    f1 -= clop[1];
	    g1 -= clo[2];
	    h1 -= clop[2];
/* --TREAT SECOND SET OF DATA IF THEY EXIST */
	    if (icode >= 4 && its6d == 0) {
		c1 -= di0x * h1;
		d1 -= dip0x * h1;
		e1 -= di0z * h1;
		f1 -= dip0z * h1;
	    }
	    xyzv[0] = c1;
	    xyzv[1] = d1;
	    xyzv[2] = e1;
	    xyzv[3] = f1;
	    xyzv[4] = g1;
	    xyzv[5] = h1;
/* --TRANSFER SECOND SET OF DATA */
	    for (iq = 1; iq <= 6; ++iq) {
		txyz[iq - 1] = 0.;
		for (jq = 1; jq <= 6; ++jq) {
		    txyz[iq - 1] += t[jq + iq * 6 - 7] * xyzv[jq - 1];
/* L190: */
		}
/* L180: */
	    }
	    c1 = txyz[0];
	    d1 = txyz[1];
	    e1 = txyz[2];
	    f1 = txyz[3];
	    g1 = txyz[4];
/* --!!IMPORTANT THE MOMENTUM HAS A TRIVIAL SCALING!! */
	    h1 = txyz[5] * 1e3;
	}
/* --OBEY DEMANDED ORDER OF PHASE SPACE */
	if (*idam < 3) {
	    g = 0.;
	    h__ = 0.;
	    g1 = 0.;
	    h1 = 0.;
	}
	if (*idam == 1) {
	    e = 0.;
	    f = 0.;
	    e1 = 0.;
	    f1 = 0.;
	}
	if (*ntwin == 1) {
	    io___586.ciunit = nfile0;
	    s_wsfe(&io___586);
	    do_fio(&c__1, (char *)&c__, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&d__, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&e, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&f, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&g, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&h__, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	if (*ntwin == 2) {
	    io___587.ciunit = nfile0;
	    s_wsfe(&io___587);
	    do_fio(&c__1, (char *)&c__, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&d__, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&e, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&f, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&g, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&h__, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	    io___588.ciunit = nfile1;
	    s_wsfe(&io___588);
	    do_fio(&c__1, (char *)&c1, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&d1, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&e1, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&f1, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&g1, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&h1, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
/* L150: */
    }
L999:
    al__1.aerr = 0;
    al__1.aunit = *nfile;
    f_rew(&al__1);
    al__1.aerr = 0;
    al__1.aunit = nfile0;
    f_rew(&al__1);
    al__1.aerr = 0;
    al__1.aunit = nfile1;
    f_rew(&al__1);
    return 0;
} /* readric_ */

/* Subroutine */ int writeric_(integer *nfile, integer *ntotal, integer *
	ntwin, integer *numl, integer *iconv)
{
    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2;
    alist al__1;

    /* Builtin functions */
    integer f_rew(alist *), s_rsue(cilist *), do_uio(integer *, char *, 
	    ftnlen), e_rsue(void);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsue(cilist *), e_wsue(void);
    double atan(doublereal);
    integer s_rsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_rsle(void);

    /* Local variables */
    static doublereal b, c__, d__, e, f, g, h__;
    static integer i__, j;
    static doublereal p, t[36]	/* was [6][6] */, c1, d1, e1, f1, g1, h1, p1;
    static integer ia, i11, i22;
    static doublereal ta[36]	/* was [6][6] */, pi;
    static integer iq, jq;
    static doublereal clo[3], qwc[3], di0x, di0z;
    static integer num1;
    static doublereal clop[3], dnms, txyz[6], xyzv[6], dip0x, dip0z;
    static integer its6d;
    static doublereal dizu0;
    static char cdate[8];
    static doublereal dmmac;
    static integer icode, ilapa, ndiff, ifipa;
    static char ctime[8];
    static integer itopa;
    static doublereal tasum, dummy;
    static char prgram[8];
    static doublereal dnumlr;
    static char sixtit[80], comment[80];

    /* Fortran I/O blocks */
    static cilist io___589 = { 0, 0, 0, 0, 0 };
    static cilist io___613 = { 0, 0, 1, 0, 0 };
    static cilist io___623 = { 0, 0, 1, 0, 0 };
    static cilist io___626 = { 0, 0, 0, 0, 0 };
    static cilist io___633 = { 0, 91, 1, 0, 0 };
    static cilist io___634 = { 0, 91, 1, 0, 0 };
    static cilist io___635 = { 0, 92, 1, 0, 0 };
    static cilist io___647 = { 0, 0, 0, 0, 0 };
    static cilist io___648 = { 0, 0, 0, 0, 0 };


/* ======================================================================= */

/* SUBROUTINE WRITERIC */

/* READS THE PROCESSED ASCII FILE FROM THE UNIT 91 AND 92 IF THERE */
/* IS A TWIN PARTICLE. */

/* AND PLUGS THEM INTO A SIXTRACK BINARY FILE IN UNIT NFILE. */


/* ======================================================================= */
/* $OMP THREADPRIVATE(i,i11,i22,ia,icode,ifipa,ilapa,iq,itopa,its6d,j,jq, */
/* $OMP&              ndiff,num1, */
/* $OMP&b,c,c1,clo,clop,d,d1,di0x,di0z,dip0x,dip0z,dizu0, */
/* $OMP&dmmac,dnms,dnumlr,dummy,e,e1,f,f1,g,g1,h,h1,p,pi,p1, */
/* $OMP&qwc,t,ta,tasum,txyz,xyzv,sixtit,comment,cdate,ctime,prgram) */
/* .....READS AGAIN THE HEADER AND CHECK FOR THE ACTUAL NUMBER OF TURNS */
    al__1.aerr = 0;
    al__1.aunit = *nfile;
    f_rew(&al__1);
    io___589.ciunit = *nfile;
    s_rsue(&io___589);
    do_uio(&c__1, sixtit, (ftnlen)80);
    do_uio(&c__1, comment, (ftnlen)80);
    do_uio(&c__1, cdate, (ftnlen)8);
    do_uio(&c__1, ctime, (ftnlen)8);
    do_uio(&c__1, prgram, (ftnlen)8);
    do_uio(&c__1, (char *)&ifipa, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&ilapa, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&itopa, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&icode, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&num1, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&qwc[0], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&qwc[1], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&qwc[2], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&clo[0], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&clop[0], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&clo[1], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&clop[1], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&clo[2], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&clop[2], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&di0x, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dip0x, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&di0z, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dip0z, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[0], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[6], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[12], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[18], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[24], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[30], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[1], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[7], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[13], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[19], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[25], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[31], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[2], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[8], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[14], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[20], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[26], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[32], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[3], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[9], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[15], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[21], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[27], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[33], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[4], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[10], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[16], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[22], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[28], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[34], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[5], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[11], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[17], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[23], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[29], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[35], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dmmac, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dnms, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dizu0, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dnumlr, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    e_rsue();
    io___613.ciunit = *nfile;
    i__1 = s_rsue(&io___613);
    if (i__1 != 0) {
	goto L999;
    }
    i__1 = do_uio(&c__1, (char *)&i11, (ftnlen)sizeof(integer));
    if (i__1 != 0) {
	goto L999;
    }
    i__1 = do_uio(&c__1, (char *)&ifipa, (ftnlen)sizeof(integer));
    if (i__1 != 0) {
	goto L999;
    }
    i__1 = do_uio(&c__1, (char *)&b, (ftnlen)sizeof(doublereal));
    if (i__1 != 0) {
	goto L999;
    }
    i__1 = do_uio(&c__1, (char *)&c__, (ftnlen)sizeof(doublereal));
    if (i__1 != 0) {
	goto L999;
    }
    i__1 = do_uio(&c__1, (char *)&d__, (ftnlen)sizeof(doublereal));
    if (i__1 != 0) {
	goto L999;
    }
    i__1 = do_uio(&c__1, (char *)&e, (ftnlen)sizeof(doublereal));
    if (i__1 != 0) {
	goto L999;
    }
    i__1 = do_uio(&c__1, (char *)&f, (ftnlen)sizeof(doublereal));
    if (i__1 != 0) {
	goto L999;
    }
    i__1 = do_uio(&c__1, (char *)&g, (ftnlen)sizeof(doublereal));
    if (i__1 != 0) {
	goto L999;
    }
    i__1 = do_uio(&c__1, (char *)&h__, (ftnlen)sizeof(doublereal));
    if (i__1 != 0) {
	goto L999;
    }
    i__1 = do_uio(&c__1, (char *)&p, (ftnlen)sizeof(doublereal));
    if (i__1 != 0) {
	goto L999;
    }
    i__1 = e_rsue();
    if (i__1 != 0) {
	goto L999;
    }
    io___623.ciunit = *nfile;
    i__1 = s_rsue(&io___623);
    if (i__1 != 0) {
	goto L999;
    }
    i__1 = do_uio(&c__1, (char *)&i22, (ftnlen)sizeof(integer));
    if (i__1 != 0) {
	goto L999;
    }
    i__1 = e_rsue();
    if (i__1 != 0) {
	goto L999;
    }
    ndiff = i22 - i11;
    al__1.aerr = 0;
    al__1.aunit = *nfile;
    f_rew(&al__1);
    s_copy(comment, "SUSSIX TREATED DATA", (ftnlen)80, (ftnlen)19);
    al__1.aerr = 0;
    al__1.aunit = 91;
    f_rew(&al__1);
    al__1.aerr = 0;
    al__1.aunit = 92;
    f_rew(&al__1);
    al__1.aerr = 0;
    al__1.aunit = *nfile;
    f_rew(&al__1);
/* .....WRITES THE SAME HEADER AS THE INPUT FILE */
    io___626.ciunit = *nfile;
    s_wsue(&io___626);
    do_uio(&c__1, sixtit, (ftnlen)80);
    do_uio(&c__1, comment, (ftnlen)80);
    do_uio(&c__1, cdate, (ftnlen)8);
    do_uio(&c__1, ctime, (ftnlen)8);
    do_uio(&c__1, prgram, (ftnlen)8);
    do_uio(&c__1, (char *)&ifipa, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&ilapa, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&itopa, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&icode, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&num1, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&qwc[0], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&qwc[1], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&qwc[2], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&clo[0], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&clop[0], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&clo[1], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&clop[1], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&clo[2], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&clop[2], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&di0x, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dip0x, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&di0z, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dip0z, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[0], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[6], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[12], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[18], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[24], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[30], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[1], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[7], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[13], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[19], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[25], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[31], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[2], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[8], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[14], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[20], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[26], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[32], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[3], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[9], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[15], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[21], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[27], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[33], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[4], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[10], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[16], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[22], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[28], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[34], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[5], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[11], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[17], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[23], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[29], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&ta[35], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dmmac, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dnms, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dizu0, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dnumlr, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&dummy, (ftnlen)sizeof(doublereal));
    e_wsue();
/* --------------------------------------------------------------------- */
    pi = atan(1.) * 4.;
/* .....CONVERTS THE DATA FROM NORMALIZED COORDINATE TO PHISICAL COORDINATES */
/* --REPAIR PARTIAL OR TOTAL INCOMPLETE TRANSFER MATRIX */
    if (abs(ta[0]) <= 1e-17 && abs(ta[7]) <= 1e-17) {
	ta[0] = 1.;
	ta[7] = 1.;
    }
    if (abs(ta[14]) <= 1e-17 && abs(ta[21]) <= 1e-17) {
	ta[14] = 1.;
	ta[21] = 1.;
    }
    if (abs(ta[28]) <= 1e-17 && abs(ta[35]) <= 1e-17) {
	ta[28] = 1.;
	ta[35] = 1.;
    }
    its6d = 0;
/* --Convert if requested */
    if (*iconv != 1) {
	for (i__ = 1; i__ <= 6; ++i__) {
	    for (j = 1; j <= 6; ++j) {
		if (i__ != j) {
		    ta[i__ + j * 6 - 7] = 0.;
		} else {
		    ta[i__ + j * 6 - 7] = 1.;
		}
	    }
	}
    }
/* --TEST IF TRANSFER MATRIX HAS LONGITUDINAL PART */
    for (i__ = 1; i__ <= 6; ++i__) {
	tasum = tasum + (d__1 = ta[i__ + 23], abs(d__1)) + (d__2 = ta[i__ + 
		29], abs(d__2));
/* L110: */
    }
    for (i__ = 1; i__ <= 4; ++i__) {
	tasum = tasum + (d__1 = ta[i__ * 6 - 2], abs(d__1)) + (d__2 = ta[i__ *
		 6 - 1], abs(d__2));
/* L120: */
    }
    tasum += -2.;
    if (abs(tasum) >= 1e-17) {
	its6d = 1;
    }
/* --TRANSPOSE MATRIX */
    for (i__ = 1; i__ <= 6; ++i__) {
	for (j = 1; j <= 6; ++j) {
	    t[i__ + j * 6 - 7] = ta[j + i__ * 6 - 7];
/* L140: */
	}
/* L130: */
    }
/* --CHECK IF 1 OR 2 SETS OF COORDINATES ARE WRITTEN */
    *ntwin = 1;
    if (ilapa != ifipa) {
	*ntwin = 2;
    }
/*      write(6,*)'WRITING SUSSIX TREATED DATA INTO THE BINARY FILE' */
    i__1 = *numl;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (*ntwin == 1) {
	    i__2 = s_rsle(&io___633);
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = do_lio(&c__5, &c__1, (char *)&c__, (ftnlen)sizeof(
		    doublereal));
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = do_lio(&c__5, &c__1, (char *)&d__, (ftnlen)sizeof(
		    doublereal));
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = do_lio(&c__5, &c__1, (char *)&e, (ftnlen)sizeof(doublereal)
		    );
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = do_lio(&c__5, &c__1, (char *)&f, (ftnlen)sizeof(doublereal)
		    );
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = do_lio(&c__5, &c__1, (char *)&g, (ftnlen)sizeof(doublereal)
		    );
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = do_lio(&c__5, &c__1, (char *)&h__, (ftnlen)sizeof(
		    doublereal));
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = e_rsle();
	    if (i__2 != 0) {
		goto L999;
	    }
	}
	if (*ntwin == 2) {
	    i__2 = s_rsle(&io___634);
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = do_lio(&c__5, &c__1, (char *)&c__, (ftnlen)sizeof(
		    doublereal));
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = do_lio(&c__5, &c__1, (char *)&d__, (ftnlen)sizeof(
		    doublereal));
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = do_lio(&c__5, &c__1, (char *)&e, (ftnlen)sizeof(doublereal)
		    );
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = do_lio(&c__5, &c__1, (char *)&f, (ftnlen)sizeof(doublereal)
		    );
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = do_lio(&c__5, &c__1, (char *)&g, (ftnlen)sizeof(doublereal)
		    );
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = do_lio(&c__5, &c__1, (char *)&h__, (ftnlen)sizeof(
		    doublereal));
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = e_rsle();
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = s_rsle(&io___635);
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = do_lio(&c__5, &c__1, (char *)&c1, (ftnlen)sizeof(
		    doublereal));
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = do_lio(&c__5, &c__1, (char *)&d1, (ftnlen)sizeof(
		    doublereal));
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = do_lio(&c__5, &c__1, (char *)&e1, (ftnlen)sizeof(
		    doublereal));
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = do_lio(&c__5, &c__1, (char *)&f1, (ftnlen)sizeof(
		    doublereal));
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = do_lio(&c__5, &c__1, (char *)&g1, (ftnlen)sizeof(
		    doublereal));
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = do_lio(&c__5, &c__1, (char *)&h1, (ftnlen)sizeof(
		    doublereal));
	    if (i__2 != 0) {
		goto L999;
	    }
	    i__2 = e_rsle();
	    if (i__2 != 0) {
		goto L999;
	    }
	}
/* --TRANSFER FIRST SET OF DATA */
	xyzv[0] = c__;
	xyzv[1] = d__;
	xyzv[2] = e;
	xyzv[3] = f;
	xyzv[4] = g;
/* --!!IMPORTANT THE MOMENTUM HAS A TRIVIAL SCALING!! */
	xyzv[5] = h__ / 1e3;
	for (iq = 1; iq <= 6; ++iq) {
	    txyz[iq - 1] = 0.;
	    for (jq = 1; jq <= 6; ++jq) {
		txyz[iq - 1] += t[jq + iq * 6 - 7] * xyzv[jq - 1];
/* L190: */
	    }
/* L180: */
	}
	c__ = txyz[0];
	d__ = txyz[1];
	e = txyz[2];
	f = txyz[3];
	g = txyz[4];
	h__ = txyz[5];
/* --!! ADD DISPERSION ONLY IF THE LONGITUDINAL */
/* --PART OF THE TRANSFER MATRIX HAS NOT BEEN */
/* --CALCULATED BUT THERE ARE SYNCHROTRON OSCILLATIONS */
	if (icode >= 4 && its6d == 0) {
	    c__ += di0x * h__;
	    d__ += dip0x * h__;
	    e += di0z * h__;
	    f += dip0z * h__;
	}
/* --ADD CLOSED ORBIT */
	c__ += clo[0];
	d__ += clop[0];
	e += clo[1];
	f += clop[1];
	g += clo[2];
	h__ += clop[2];
	if (*ntwin == 2) {
/* --TRANSFER SECOND SET OF DATA IF THEY EXIST */
	    xyzv[0] = c1;
	    xyzv[1] = d1;
	    xyzv[2] = e1;
	    xyzv[3] = f1;
	    xyzv[4] = g1;
/* --!!IMPORTANT THE MOMENTUM HAS A TRIVIAL SCALING!! */
	    xyzv[5] = h1 / 1e3;
	    for (iq = 1; iq <= 6; ++iq) {
		txyz[iq - 1] = 0.;
		for (jq = 1; jq <= 6; ++jq) {
		    txyz[iq - 1] += t[jq + iq * 6 - 7] * xyzv[jq - 1];
/* L290: */
		}
/* L280: */
	    }
	    c1 = txyz[0];
	    d1 = txyz[1];
	    e1 = txyz[2];
	    f1 = txyz[3];
	    g1 = txyz[4];
	    h1 = txyz[5];
/* --!! ADD DISPERSION ONLY IF THE LONGITUDINAL */
/* --PART OF THE TRANSFER MATRIX HAS NOT BEEN */
/* --CALCULATED BUT THERE ARE SYNCHROTRON OSCILLATIONS */
	    if (icode >= 4 && its6d == 0) {
		c1 += di0x * h1;
		d1 += dip0x * h1;
		e1 += di0z * h1;
		f1 += dip0z * h1;
	    }
/* --ADD CLOSED ORBIT */
	    c1 += clo[0];
	    d1 += clop[0];
	    e1 += clo[1];
	    f1 += clop[1];
	    g1 += clo[2];
	    h1 += clop[2];
	}
/* .....WRITES THE DATA IN BINARY FORMAT ON UNIT NFILE */
	ia = (i__ - 1) * ndiff;
	if (*ntwin == 1) {
	    io___647.ciunit = *nfile;
	    s_wsue(&io___647);
	    do_uio(&c__1, (char *)&ia, (ftnlen)sizeof(integer));
	    do_uio(&c__1, (char *)&ifipa, (ftnlen)sizeof(integer));
	    do_uio(&c__1, (char *)&b, (ftnlen)sizeof(doublereal));
	    do_uio(&c__1, (char *)&c__, (ftnlen)sizeof(doublereal));
	    do_uio(&c__1, (char *)&d__, (ftnlen)sizeof(doublereal));
	    do_uio(&c__1, (char *)&e, (ftnlen)sizeof(doublereal));
	    do_uio(&c__1, (char *)&f, (ftnlen)sizeof(doublereal));
	    do_uio(&c__1, (char *)&g, (ftnlen)sizeof(doublereal));
	    do_uio(&c__1, (char *)&h__, (ftnlen)sizeof(doublereal));
	    do_uio(&c__1, (char *)&p, (ftnlen)sizeof(doublereal));
	    e_wsue();
	} else if (*ntwin == 2) {
	    io___648.ciunit = *nfile;
	    s_wsue(&io___648);
	    do_uio(&c__1, (char *)&ia, (ftnlen)sizeof(integer));
	    do_uio(&c__1, (char *)&ifipa, (ftnlen)sizeof(integer));
	    do_uio(&c__1, (char *)&b, (ftnlen)sizeof(doublereal));
	    do_uio(&c__1, (char *)&c__, (ftnlen)sizeof(doublereal));
	    do_uio(&c__1, (char *)&d__, (ftnlen)sizeof(doublereal));
	    do_uio(&c__1, (char *)&e, (ftnlen)sizeof(doublereal));
	    do_uio(&c__1, (char *)&f, (ftnlen)sizeof(doublereal));
	    do_uio(&c__1, (char *)&g, (ftnlen)sizeof(doublereal));
	    do_uio(&c__1, (char *)&h__, (ftnlen)sizeof(doublereal));
	    do_uio(&c__1, (char *)&p, (ftnlen)sizeof(doublereal));
	    do_uio(&c__1, (char *)&ilapa, (ftnlen)sizeof(integer));
	    do_uio(&c__1, (char *)&b, (ftnlen)sizeof(doublereal));
	    do_uio(&c__1, (char *)&c1, (ftnlen)sizeof(doublereal));
	    do_uio(&c__1, (char *)&d1, (ftnlen)sizeof(doublereal));
	    do_uio(&c__1, (char *)&e1, (ftnlen)sizeof(doublereal));
	    do_uio(&c__1, (char *)&f1, (ftnlen)sizeof(doublereal));
	    do_uio(&c__1, (char *)&g1, (ftnlen)sizeof(doublereal));
	    do_uio(&c__1, (char *)&h1, (ftnlen)sizeof(doublereal));
	    do_uio(&c__1, (char *)&p1, (ftnlen)sizeof(doublereal));
	    e_wsue();
	}
/* L150: */
    }
L999:
    al__1.aerr = 0;
    al__1.aunit = *nfile;
    f_rew(&al__1);
    al__1.aerr = 0;
    al__1.aunit = 91;
    f_rew(&al__1);
    al__1.aerr = 0;
    al__1.aunit = 92;
    f_rew(&al__1);
    return 0;
} /* writeric_ */

/* Subroutine */ int kerset_0_(int n__, char *ercode, integer *lgfile, 
	integer *limitm, integer *limitr, integer *log__, logical *mflag, 
	logical *rflag, ftnlen ercode_len)
{
    /* Initialized data */

    static integer logf = 0;
    static char code[6*27] = "C204.1" "C204.2" "C204.3" "C205.1" "C205.2" 
	    "C305.1" "C308.1" "C312.1" "C313.1" "C336.1" "C337.1" "C341.1" 
	    "D103.1" "D106.1" "D209.1" "D509.1" "E100.1" "E104.1" "E105.1" 
	    "E208.1" "E208.2" "F010.1" "F011.1" "F012.1" "F406.1" "G100.1" 
	    "G100.2";
    static integer kntm[27] = { 255,255,255,255,255,255,255,255,255,255,255,
	    255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255 };
    static integer kntr[27] = { 255,255,255,255,255,255,255,255,255,255,255,
	    255,255,255,255,255,255,255,255,255,255,0,0,0,0,255,255 };

    /* Format strings */
    static char fmt_1000[] = "(\002 KERNLIB LIBRARY ERROR. \002/\002 ERROR C"
	    "ODE \002,a6,\002 NOT RECOGNIZED BY KERMTR\002,\002 ERROR MONITOR"
	    ". RUN ABORTED.\002)";
    static char fmt_1001[] = "(/\002 ***** RUN TERMINATED BY CERN LIBRARY ER"
	    "ROR \002,\002CONDITION \002,a6)";
    static char fmt_1002[] = "(/\002 ***** CERN LIBRARY ERROR CONDITION \002"
	    ",a6)";

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer i__, l;
    extern /* Subroutine */ int abend_(void);

    /* Fortran I/O blocks */
    static cilist io___656 = { 0, 6, 0, fmt_1000, 0 };
    static cilist io___657 = { 0, 6, 0, fmt_1001, 0 };
    static cilist io___658 = { 0, 0, 0, fmt_1001, 0 };
    static cilist io___659 = { 0, 6, 0, fmt_1002, 0 };
    static cilist io___660 = { 0, 0, 0, fmt_1002, 0 };


/* ----------------------------------------------------------------------- */
    switch(n__) {
	case 1: goto L_kermtr;
	}

/* ----------------------------------------------------------------------- */
/* $OMP THREADPRIVATE(i,l,logf,kntm,kntr, */
/* $OMP&              code) */
    logf = *lgfile;
    l = 0;
    if (s_cmp(ercode, " ", (ftnlen)6, (ftnlen)1) != 0) {
	for (l = 1; l <= 6; ++l) {
	    if (s_cmp(ercode, ercode, l, (ftnlen)6) == 0) {
		goto L12;
	    }
/* L10: */
	}
L12:
	;
    }
    for (i__ = 1; i__ <= 27; ++i__) {
	if (l == 0) {
	    goto L13;
	}
	if (s_cmp(code + (i__ - 1) * 6, ercode, l, l) != 0) {
	    goto L14;
	}
L13:
	if (*limitm >= 0) {
	    kntm[i__ - 1] = *limitm;
	}
	if (*limitr >= 0) {
	    kntr[i__ - 1] = *limitr;
	}
L14:
	;
    }
    return 0;

L_kermtr:
    *log__ = logf;
    for (i__ = 1; i__ <= 27; ++i__) {
	if (s_cmp(ercode, code + (i__ - 1) * 6, (ftnlen)6, (ftnlen)6) == 0) {
	    goto L21;
	}
/* L20: */
    }
    s_wsfe(&io___656);
    do_fio(&c__1, ercode, (ftnlen)6);
    e_wsfe();
    abend_();
    return 0;
L21:
    *rflag = kntr[i__ - 1] >= 1;
    if (*rflag && kntr[i__ - 1] < 255) {
	--kntr[i__ - 1];
    }
    *mflag = kntm[i__ - 1] >= 1;
    if (*mflag && kntm[i__ - 1] < 255) {
	--kntm[i__ - 1];
    }
    if (! (*rflag)) {
	if (logf < 1) {
	    s_wsfe(&io___657);
	    do_fio(&c__1, code + (i__ - 1) * 6, (ftnlen)6);
	    e_wsfe();
	} else {
	    io___658.ciunit = logf;
	    s_wsfe(&io___658);
	    do_fio(&c__1, code + (i__ - 1) * 6, (ftnlen)6);
	    e_wsfe();
	}
    }
    if (*mflag && *rflag) {
	if (logf < 1) {
	    s_wsfe(&io___659);
	    do_fio(&c__1, code + (i__ - 1) * 6, (ftnlen)6);
	    e_wsfe();
	} else {
	    io___660.ciunit = logf;
	    s_wsfe(&io___660);
	    do_fio(&c__1, code + (i__ - 1) * 6, (ftnlen)6);
	    e_wsfe();
	}
    }
    return 0;
} /* kerset_ */

/* Subroutine */ int kerset_(char *ercode, integer *lgfile, integer *limitm, 
	integer *limitr, ftnlen ercode_len)
{
    return kerset_0_(0, ercode, lgfile, limitm, limitr, (integer *)0, (
	    logical *)0, (logical *)0, ercode_len);
    }

/* Subroutine */ int kermtr_(char *ercode, integer *log__, logical *mflag, 
	logical *rflag, ftnlen ercode_len)
{
    return kerset_0_(1, ercode, (integer *)0, (integer *)0, (integer *)0, 
	    log__, mflag, rflag, ercode_len);
    }

/* Subroutine */ int rinv_(integer *n, real *a, integer *idim, integer *ir, 
	integer *ifail)
{
    /* Initialized data */

    static char name__[6] = "RINV  ";
    static integer kprnt = 0;

    /* System generated locals */
    integer a_dim1, a_offset;
    real r__1;

    /* Local variables */
    static integer k;
    static real s, t1, t2, t3, c11, c12, c13, c21, c22, c23, c31, c32, c33, 
	    det, temp;
    extern /* Subroutine */ int f010pr_(char *, integer *, integer *, integer 
	    *, integer *, ftnlen);
    static integer jfail;
    extern /* Subroutine */ int rfact_(integer *, real *, integer *, integer *
	    , integer *, real *, integer *), rfinv_(integer *, real *, 
	    integer *, integer *);

/* ----------------------------------------------------------------------- */

/*     ****************************************************************** */

/*     REPLACES A BY ITS INVERSE. */

/*     (PARAMETERS AS FOR REQINV.) */

/*     CALLS ... RFACT, RFINV, F010PR, ABEND. */

/*     ****************************************************************** */
/* ----------------------------------------------------------------------- */
    /* Parameter adjustments */
    --ir;
    a_dim1 = *idim;
    a_offset = 1 + a_dim1;
    a -= a_offset;

    /* Function Body */
/* $OMP THREADPRIVATE(jfail,k,kprnt, */
/* $OMP& t1,t2,t3,det,temp,s,c11,c12,c13,c21,c22,c23,c31,c32,c33) */
/* ----------------------------------------------------------------------- */

/*  TEST FOR PARAMETER ERRORS. */

    if (*n < 1 || *n > *idim) {
	goto L7;
    }

/*  TEST FOR N.LE.3. */

    if (*n > 3) {
	goto L6;
    }
    *ifail = 0;
    if (*n < 3) {
	goto L4;
    }

/*  N=3 CASE. */

/*     COMPUTE COFACTORS. */
    c11 = a[(a_dim1 << 1) + 2] * a[a_dim1 * 3 + 3] - a[a_dim1 * 3 + 2] * a[(
	    a_dim1 << 1) + 3];
    c12 = a[a_dim1 * 3 + 2] * a[a_dim1 + 3] - a[a_dim1 + 2] * a[a_dim1 * 3 + 
	    3];
    c13 = a[a_dim1 + 2] * a[(a_dim1 << 1) + 3] - a[(a_dim1 << 1) + 2] * a[
	    a_dim1 + 3];
    c21 = a[(a_dim1 << 1) + 3] * a[a_dim1 * 3 + 1] - a[a_dim1 * 3 + 3] * a[(
	    a_dim1 << 1) + 1];
    c22 = a[a_dim1 * 3 + 3] * a[a_dim1 + 1] - a[a_dim1 + 3] * a[a_dim1 * 3 + 
	    1];
    c23 = a[a_dim1 + 3] * a[(a_dim1 << 1) + 1] - a[(a_dim1 << 1) + 3] * a[
	    a_dim1 + 1];
    c31 = a[(a_dim1 << 1) + 1] * a[a_dim1 * 3 + 2] - a[a_dim1 * 3 + 1] * a[(
	    a_dim1 << 1) + 2];
    c32 = a[a_dim1 * 3 + 1] * a[a_dim1 + 2] - a[a_dim1 + 1] * a[a_dim1 * 3 + 
	    2];
    c33 = a[a_dim1 + 1] * a[(a_dim1 << 1) + 2] - a[(a_dim1 << 1) + 1] * a[
	    a_dim1 + 2];
    t1 = (r__1 = a[a_dim1 + 1], dabs(r__1));
    t2 = (r__1 = a[a_dim1 + 2], dabs(r__1));
    t3 = (r__1 = a[a_dim1 + 3], dabs(r__1));

/*     (SET TEMP=PIVOT AND DET=PIVOT*DET.) */
    if (t1 >= t2) {
	goto L1;
    }
    if (t3 >= t2) {
	goto L2;
    }
/*        (PIVOT IS A21) */
    temp = a[a_dim1 + 2];
    det = c13 * c32 - c12 * c33;
    goto L3;
L1:
    if (t3 >= t1) {
	goto L2;
    }
/*     (PIVOT IS A11) */
    temp = a[a_dim1 + 1];
    det = c22 * c33 - c23 * c32;
    goto L3;
/*     (PIVOT IS A31) */
L2:
    temp = a[a_dim1 + 3];
    det = c23 * c12 - c22 * c13;

/*     SET ELEMENTS OF INVERSE IN A. */
L3:
    if (det == 0.f) {
	goto L8;
    }
    s = temp / det;
    a[a_dim1 + 1] = s * c11;
    a[(a_dim1 << 1) + 1] = s * c21;
    a[a_dim1 * 3 + 1] = s * c31;
    a[a_dim1 + 2] = s * c12;
    a[(a_dim1 << 1) + 2] = s * c22;
    a[a_dim1 * 3 + 2] = s * c32;
    a[a_dim1 + 3] = s * c13;
    a[(a_dim1 << 1) + 3] = s * c23;
    a[a_dim1 * 3 + 3] = s * c33;
    return 0;

L4:
    if (*n < 2) {
	goto L5;
    }

/*  N=2 CASE BY CRAMERS RULE. */

    det = a[a_dim1 + 1] * a[(a_dim1 << 1) + 2] - a[(a_dim1 << 1) + 1] * a[
	    a_dim1 + 2];
    if (det == 0.f) {
	goto L8;
    }
    s = 1.f / det;
    c11 = s * a[(a_dim1 << 1) + 2];
    a[(a_dim1 << 1) + 1] = -s * a[(a_dim1 << 1) + 1];
    a[a_dim1 + 2] = -s * a[a_dim1 + 2];
    a[(a_dim1 << 1) + 2] = s * a[a_dim1 + 1];
    a[a_dim1 + 1] = c11;
    return 0;

/*  N=1 CASE. */

L5:
    if (a[a_dim1 + 1] == 0.f) {
	goto L8;
    }
    a[a_dim1 + 1] = 1.f / a[a_dim1 + 1];
    return 0;

/*  N.GT.3 CASES.  FACTORIZE MATRIX AND INVERT. */

L6:
    rfact_(n, &a[a_offset], idim, &ir[1], ifail, &det, &jfail);
    if (*ifail != 0) {
	return 0;
    }
    rfinv_(n, &a[a_offset], idim, &ir[1]);
    return 0;

/*  ERROR EXITS. */

L7:
    *ifail = 1;
    f010pr_(name__, n, idim, &k, &kprnt, (ftnlen)6);
    return 0;

L8:
    *ifail = -1;
    return 0;

} /* rinv_ */

/* Subroutine */ int dinv_(integer *n, doublereal *a, integer *idim, integer *
	ir, integer *ifail)
{
    /* Initialized data */

    static char name__[6] = "DINV  ";
    static integer kprnt = 0;

    /* System generated locals */
    integer a_dim1, a_offset;
    real r__1;

    /* Local variables */
    static integer k;
    static doublereal s;
    static real t1, t2, t3;
    static doublereal c11, c12, c13, c21, c22, c23, c31, c32, c33, det, temp;
    extern /* Subroutine */ int f010pr_(char *, integer *, integer *, integer 
	    *, integer *, ftnlen), dfact_(integer *, doublereal *, integer *, 
	    integer *, integer *, doublereal *, integer *);
    static integer jfail;
    extern /* Subroutine */ int dfinv_(integer *, doublereal *, integer *, 
	    integer *);

/* ----------------------------------------------------------------------- */

/*     ****************************************************************** */

/*     REPLACES A BY ITS INVERSE. */

/*     (PARAMETERS AS FOR DEQINV.) */

/*     CALLS ... DFACT, DFINV, F010PR, ABEND. */

/*     ****************************************************************** */
/* ----------------------------------------------------------------------- */
    /* Parameter adjustments */
    --ir;
    a_dim1 = *idim;
    a_offset = 1 + a_dim1;
    a -= a_offset;

    /* Function Body */
/* $OMP THREADPRIVATE(jfail,k,kprnt, */
/* $OMP& det,temp,s,c11,c12,c13,c21,c22,c23,c31,c32,c33,t1,t2,t3,name) */
/* ----------------------------------------------------------------------- */

/*  TEST FOR PARAMETER ERRORS. */

    if (*n < 1 || *n > *idim) {
	goto L7;
    }

/*  TEST FOR N.LE.3. */

    if (*n > 3) {
	goto L6;
    }
    *ifail = 0;
    if (*n < 3) {
	goto L4;
    }

/*  N=3 CASE. */

/*     COMPUTE COFACTORS. */
    c11 = a[(a_dim1 << 1) + 2] * a[a_dim1 * 3 + 3] - a[a_dim1 * 3 + 2] * a[(
	    a_dim1 << 1) + 3];
    c12 = a[a_dim1 * 3 + 2] * a[a_dim1 + 3] - a[a_dim1 + 2] * a[a_dim1 * 3 + 
	    3];
    c13 = a[a_dim1 + 2] * a[(a_dim1 << 1) + 3] - a[(a_dim1 << 1) + 2] * a[
	    a_dim1 + 3];
    c21 = a[(a_dim1 << 1) + 3] * a[a_dim1 * 3 + 1] - a[a_dim1 * 3 + 3] * a[(
	    a_dim1 << 1) + 1];
    c22 = a[a_dim1 * 3 + 3] * a[a_dim1 + 1] - a[a_dim1 + 3] * a[a_dim1 * 3 + 
	    1];
    c23 = a[a_dim1 + 3] * a[(a_dim1 << 1) + 1] - a[(a_dim1 << 1) + 3] * a[
	    a_dim1 + 1];
    c31 = a[(a_dim1 << 1) + 1] * a[a_dim1 * 3 + 2] - a[a_dim1 * 3 + 1] * a[(
	    a_dim1 << 1) + 2];
    c32 = a[a_dim1 * 3 + 1] * a[a_dim1 + 2] - a[a_dim1 + 1] * a[a_dim1 * 3 + 
	    2];
    c33 = a[a_dim1 + 1] * a[(a_dim1 << 1) + 2] - a[(a_dim1 << 1) + 1] * a[
	    a_dim1 + 2];
    t1 = (r__1 = (real) a[a_dim1 + 1], dabs(r__1));
    t2 = (r__1 = (real) a[a_dim1 + 2], dabs(r__1));
    t3 = (r__1 = (real) a[a_dim1 + 3], dabs(r__1));

/*     (SET TEMP=PIVOT AND DET=PIVOT*DET.) */
    if (t1 >= t2) {
	goto L1;
    }
    if (t3 >= t2) {
	goto L2;
    }
/*        (PIVOT IS A21) */
    temp = a[a_dim1 + 2];
    det = c13 * c32 - c12 * c33;
    goto L3;
L1:
    if (t3 >= t1) {
	goto L2;
    }
/*     (PIVOT IS A11) */
    temp = a[a_dim1 + 1];
    det = c22 * c33 - c23 * c32;
    goto L3;
/*     (PIVOT IS A31) */
L2:
    temp = a[a_dim1 + 3];
    det = c23 * c12 - c22 * c13;

/*     SET ELEMENTS OF INVERSE IN A. */
L3:
    if (det == 0.) {
	goto L8;
    }
    s = temp / det;
    a[a_dim1 + 1] = s * c11;
    a[(a_dim1 << 1) + 1] = s * c21;
    a[a_dim1 * 3 + 1] = s * c31;
    a[a_dim1 + 2] = s * c12;
    a[(a_dim1 << 1) + 2] = s * c22;
    a[a_dim1 * 3 + 2] = s * c32;
    a[a_dim1 + 3] = s * c13;
    a[(a_dim1 << 1) + 3] = s * c23;
    a[a_dim1 * 3 + 3] = s * c33;
    return 0;

L4:
    if (*n < 2) {
	goto L5;
    }

/*  N=2 CASE BY CRAMERS RULE. */

    det = a[a_dim1 + 1] * a[(a_dim1 << 1) + 2] - a[(a_dim1 << 1) + 1] * a[
	    a_dim1 + 2];
    if (det == 0.) {
	goto L8;
    }
    s = 1. / det;
    c11 = s * a[(a_dim1 << 1) + 2];
    a[(a_dim1 << 1) + 1] = -s * a[(a_dim1 << 1) + 1];
    a[a_dim1 + 2] = -s * a[a_dim1 + 2];
    a[(a_dim1 << 1) + 2] = s * a[a_dim1 + 1];
    a[a_dim1 + 1] = c11;
    return 0;

/*  N=1 CASE. */

L5:
    if (a[a_dim1 + 1] == 0.) {
	goto L8;
    }
    a[a_dim1 + 1] = 1. / a[a_dim1 + 1];
    return 0;

/*  N.GT.3 CASES.  FACTORIZE MATRIX AND INVERT. */

L6:
    dfact_(n, &a[a_offset], idim, &ir[1], ifail, &det, &jfail);
    if (*ifail != 0) {
	return 0;
    }
    dfinv_(n, &a[a_offset], idim, &ir[1]);
    return 0;

/*  ERROR EXITS. */

L7:
    *ifail = 1;
    f010pr_(name__, n, idim, &k, &kprnt, (ftnlen)6);
    return 0;

L8:
    *ifail = -1;
    return 0;

} /* dinv_ */

/* Subroutine */ int f010pr_(char *name__, integer *n, integer *idim, integer 
	*k, integer *kprnt, ftnlen name_len)
{
    /* Format strings */
    static char fmt_2000[] = "(7x,\002subroutine \002,a6,\002 ... paramete"
	    "r\002,\002 error (n.lt.1 or n.gt.idim).\002,6x,\002n =\002,i4,6x,"
	    "\002idim =\002,i4,\002.\002)";
    static char fmt_2001[] = "(7x,\002subroutine \002,a6,\002 ... paramete"
	    "r\002,\002 error (n.lt.1 or n.gt.idim or k.lt.1).\002,6x,\002n "
	    "=\002,i4,6x,\002idim =\002,i4,6x,\002k =\002,i4,\002.\002)";

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    extern /* Subroutine */ int abend_(void);
    static logical mflag, rflag;
    static integer lgfile;
    extern /* Subroutine */ int kermtr_(char *, integer *, logical *, logical 
	    *, ftnlen);

    /* Fortran I/O blocks */
    static cilist io___702 = { 0, 6, 0, fmt_2000, 0 };
    static cilist io___703 = { 0, 6, 0, fmt_2001, 0 };
    static cilist io___704 = { 0, 0, 0, fmt_2000, 0 };
    static cilist io___705 = { 0, 0, 0, fmt_2001, 0 };


/*     ****************************************************************** */

/*     PRINT ROUTINE FOR PARAMETER ERRORS IN MATRIX SUBROUTINES $EQINV, */
/*     $EQN, $INV (WHERE $ IS A LETTER SPECIFYING THE ARITHMETIC TYPE). */

/*     NAME         (CHARACTER*6) NAME OF THE CALLING ROUTINE. */

/*     N,IDIM,K     PARAMETERS OF THE CALLING ROUTINE (WITH K=0 IF K IS */
/*                  NOT TO BE PRINTED). */

/*     KPRNT        PRINT FLAG FOR K (K IS NOT PRINTED IF KPRNT=0). */

/*     ****************************************************************** */
/* $OMP THREADPRIVATE(lgfile,mflag,rflag) */
/* ----------------------------------------------------------------------- */
    kermtr_("F010.1", &lgfile, &mflag, &rflag, (ftnlen)6);
    if (mflag) {
	if (lgfile == 0) {
	    if (*kprnt == 0) {
		s_wsfe(&io___702);
		do_fio(&c__1, name__, (ftnlen)6);
		do_fio(&c__1, (char *)&(*n), (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&(*idim), (ftnlen)sizeof(integer));
		e_wsfe();
	    }
	    if (*kprnt != 0) {
		s_wsfe(&io___703);
		do_fio(&c__1, name__, (ftnlen)6);
		do_fio(&c__1, (char *)&(*n), (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&(*idim), (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&(*k), (ftnlen)sizeof(integer));
		e_wsfe();
	    }
	} else {
	    if (*kprnt == 0) {
		io___704.ciunit = lgfile;
		s_wsfe(&io___704);
		do_fio(&c__1, name__, (ftnlen)6);
		do_fio(&c__1, (char *)&(*n), (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&(*idim), (ftnlen)sizeof(integer));
		e_wsfe();
	    }
	    if (*kprnt != 0) {
		io___705.ciunit = lgfile;
		s_wsfe(&io___705);
		do_fio(&c__1, name__, (ftnlen)6);
		do_fio(&c__1, (char *)&(*n), (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&(*idim), (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&(*k), (ftnlen)sizeof(integer));
		e_wsfe();
	    }
	}
    }
    if (! rflag) {
	abend_();
    }
    return 0;

} /* f010pr_ */

/* Subroutine */ int rfact_(integer *n, real *a, integer *idim, integer *ir, 
	integer *ifail, real *det, integer *jfail)
{
    /* Initialized data */

    static real g1 = 1e-37f;
    static real g2 = 1e37f;
    static char hname[6] = " RFACT";
    static real zero = 0.f;
    static real one = 1.f;
    static integer normal = 0;
    static integer imposs = -1;
    static integer jrange = 0;
    static integer jover = 1;
    static integer junder = -1;

    /* System generated locals */
    integer a_dim1, a_offset, i__1, i__2, i__3;
    real r__1;

    /* Local variables */
    static integer i__, j, k, l;
    static real p, q, t;
    static doublereal s11, s12;
    static real tf;
    static integer jm1, jp1, nxch;
    extern /* Subroutine */ int tmprnt_(char *, integer *, integer *, integer 
	    *, ftnlen);

    /* Parameter adjustments */
    a_dim1 = *idim;
    a_offset = 1 + a_dim1;
    a -= a_offset;
    --ir;

    /* Function Body */
/* $OMP THREADPRIVATE(i,imposs,j,jm1,jover,jp1, */
/* $OMP&              jrange,junder,k,l,normal,nxch, */
/* $OMP& g1,g2,one,p,q,t,tf,x,y,zero,s11,s12,hname) */
/* ----------------------------------------------------------------------- */
    if (*idim >= *n && *n > 0) {
	goto L110;
    }
    tmprnt_(hname, n, idim, &c__0, (ftnlen)6);
    return 0;
L110:
    *ifail = normal;
    *jfail = jrange;
    nxch = 0;
    *det = one;
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
/* L120: */
	k = j;
	p = (r__1 = a[j + j * a_dim1], dabs(r__1));
	if (j == *n) {
	    goto L122;
	}
	jp1 = j + 1;
	i__2 = *n;
	for (i__ = jp1; i__ <= i__2; ++i__) {
	    q = (r__1 = a[i__ + j * a_dim1], dabs(r__1));
	    if (q <= p) {
		goto L121;
	    }
	    k = i__;
	    p = q;
L121:
	    ;
	}
	if (k != j) {
	    goto L123;
	}
L122:
	if (p > 0.f) {
	    goto L130;
	}
	*det = zero;
	*ifail = imposs;
	*jfail = jrange;
	return 0;
L123:
	i__2 = *n;
	for (l = 1; l <= i__2; ++l) {
	    tf = a[j + l * a_dim1];
	    a[j + l * a_dim1] = a[k + l * a_dim1];
	    a[k + l * a_dim1] = tf;
/* L124: */
	}
	++nxch;
	ir[nxch] = (j << 12) + k;
L130:
	*det *= a[j + j * a_dim1];
	a[j + j * a_dim1] = one / a[j + j * a_dim1];
	t = dabs(*det);
	if (t < g1) {
	    *det = zero;
	    if (*jfail == jrange) {
		*jfail = junder;
	    }
	} else if (t > g2) {
	    *det = one;
	    if (*jfail == jrange) {
		*jfail = jover;
	    }
	}
	if (j == *n) {
	    goto L144;
	}
	jm1 = j - 1;
	jp1 = j + 1;
	i__2 = *n;
	for (k = jp1; k <= i__2; ++k) {
	    s11 = -a[j + k * a_dim1];
	    s12 = -a[k + (j + 1) * a_dim1];
	    if (j == 1) {
		goto L142;
	    }
	    i__3 = jm1;
	    for (i__ = 1; i__ <= i__3; ++i__) {
		s11 = (doublereal) a[i__ + k * a_dim1] * (doublereal) a[j + 
			i__ * a_dim1] + s11;
		s12 = (doublereal) a[i__ + (j + 1) * a_dim1] * (doublereal) a[
			k + i__ * a_dim1] + s12;
/* L141: */
	    }
L142:
	    a[j + k * a_dim1] = -s11 * a[j + j * a_dim1];
	    a[k + (j + 1) * a_dim1] = -((doublereal) a[j + (j + 1) * a_dim1] *
		     (doublereal) a[k + j * a_dim1] + s12);
/* L143: */
	}
L144:
	;
    }
/* L150: */
    if (nxch % 2 != 0) {
	*det = -(*det);
    }
    if (*jfail != jrange) {
	*det = zero;
    }
    ir[*n] = nxch;
    return 0;
} /* rfact_ */

/* Subroutine */ int dfact_(integer *n, doublereal *a, integer *idim, integer 
	*ir, integer *ifail, doublereal *det, integer *jfail)
{
    /* Initialized data */

    static real g1 = 1e-37f;
    static real g2 = 1e37f;
    static char hname[6] = " DFACT";
    static doublereal zero = 0.;
    static doublereal one = 1.;
    static integer normal = 0;
    static integer imposs = -1;
    static integer jrange = 0;
    static integer jover = 1;
    static integer junder = -1;

    /* System generated locals */
    integer a_dim1, a_offset, i__1, i__2, i__3;
    real r__1;

    /* Local variables */
    static integer i__, j, k, l;
    static real p, q, t;
    static doublereal s11, s12, tf;
    static integer jm1, jp1, nxch;
    extern /* Subroutine */ int tmprnt_(char *, integer *, integer *, integer 
	    *, ftnlen);

    /* Parameter adjustments */
    a_dim1 = *idim;
    a_offset = 1 + a_dim1;
    a -= a_offset;
    --ir;

    /* Function Body */
/* $OMP THREADPRIVATE(i,imposs,j,jm1,jover,jp1, */
/* $OMP&              jrange,junder,k,l,normal,nxch, */
/* $OMP& g1,g2,p,q,t, */
/* $OMP& zero,one,s11,s12,x,y,tf,hname) */
/* ----------------------------------------------------------------------- */
    if (*idim >= *n && *n > 0) {
	goto L110;
    }
    tmprnt_(hname, n, idim, &c__0, (ftnlen)6);
    return 0;
L110:
    *ifail = normal;
    *jfail = jrange;
    nxch = 0;
    *det = one;
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
/* L120: */
	k = j;
	p = (r__1 = (real) a[j + j * a_dim1], dabs(r__1));
	if (j == *n) {
	    goto L122;
	}
	jp1 = j + 1;
	i__2 = *n;
	for (i__ = jp1; i__ <= i__2; ++i__) {
	    q = (r__1 = (real) a[i__ + j * a_dim1], dabs(r__1));
	    if (q <= p) {
		goto L121;
	    }
	    k = i__;
	    p = q;
L121:
	    ;
	}
	if (k != j) {
	    goto L123;
	}
L122:
	if (p > 0.f) {
	    goto L130;
	}
	*det = zero;
	*ifail = imposs;
	*jfail = jrange;
	return 0;
L123:
	i__2 = *n;
	for (l = 1; l <= i__2; ++l) {
	    tf = a[j + l * a_dim1];
	    a[j + l * a_dim1] = a[k + l * a_dim1];
	    a[k + l * a_dim1] = tf;
/* L124: */
	}
	++nxch;
	ir[nxch] = (j << 12) + k;
L130:
	*det *= a[j + j * a_dim1];
	a[j + j * a_dim1] = one / a[j + j * a_dim1];
	t = (r__1 = (real) (*det), dabs(r__1));
	if (t < g1) {
	    *det = zero;
	    if (*jfail == jrange) {
		*jfail = junder;
	    }
	} else if (t > g2) {
	    *det = one;
	    if (*jfail == jrange) {
		*jfail = jover;
	    }
	}
	if (j == *n) {
	    goto L144;
	}
	jm1 = j - 1;
	jp1 = j + 1;
	i__2 = *n;
	for (k = jp1; k <= i__2; ++k) {
	    s11 = -a[j + k * a_dim1];
	    s12 = -a[k + (j + 1) * a_dim1];
	    if (j == 1) {
		goto L142;
	    }
	    i__3 = jm1;
	    for (i__ = 1; i__ <= i__3; ++i__) {
		s11 = a[i__ + k * a_dim1] * a[j + i__ * a_dim1] + s11;
		s12 = a[i__ + (j + 1) * a_dim1] * a[k + i__ * a_dim1] + s12;
/* L141: */
	    }
L142:
	    a[j + k * a_dim1] = -s11 * a[j + j * a_dim1];
	    a[k + (j + 1) * a_dim1] = -(a[j + (j + 1) * a_dim1] * a[k + j * 
		    a_dim1] + s12);
/* L143: */
	}
L144:
	;
    }
/* L150: */
    if (nxch % 2 != 0) {
	*det = -(*det);
    }
    if (*jfail != jrange) {
	*det = zero;
    }
    ir[*n] = nxch;
    return 0;
} /* dfact_ */

/* Subroutine */ int rfeqn_(integer *n, real *a, integer *idim, integer *ir, 
	integer *k, real *b)
{
    /* Initialized data */

    static char hname[6] = " RFEQN";

    /* System generated locals */
    integer a_dim1, a_offset, b_dim1, b_offset, i__1, i__2, i__3;

    /* Local variables */
    static integer i__, j, l, m, ij;
    static doublereal s21, s22;
    static real te;
    static integer im1, nm1, nmi, nxch, nmjp1;
    extern /* Subroutine */ int tmprnt_(char *, integer *, integer *, integer 
	    *, ftnlen);

    /* Parameter adjustments */
    b_dim1 = *idim;
    b_offset = 1 + b_dim1;
    b -= b_offset;
    a_dim1 = *idim;
    a_offset = 1 + a_dim1;
    a -= a_offset;
    --ir;

    /* Function Body */
/* $OMP THREADPRIVATE(i,ij,im1,j,l,m,nm1,nmi,nmjp1,nxch, */
/* $OMP&              te,x,y,s21,s22,hname) */
/* ----------------------------------------------------------------------- */
    if (*idim >= *n && *n > 0 && *k > 0) {
	goto L210;
    }
    tmprnt_(hname, n, idim, k, (ftnlen)6);
    return 0;
L210:
    nxch = ir[*n];
    if (nxch == 0) {
	goto L220;
    }
    i__1 = nxch;
    for (m = 1; m <= i__1; ++m) {
	ij = ir[m];
	i__ = ij / 4096;
	j = ij % 4096;
	i__2 = *k;
	for (l = 1; l <= i__2; ++l) {
	    te = b[i__ + l * b_dim1];
	    b[i__ + l * b_dim1] = b[j + l * b_dim1];
	    b[j + l * b_dim1] = te;
/* L211: */
	}
/* L212: */
    }
L220:
    i__1 = *k;
    for (l = 1; l <= i__1; ++l) {
	b[l * b_dim1 + 1] = a[a_dim1 + 1] * b[l * b_dim1 + 1];
/* L221: */
    }
    if (*n == 1) {
	goto L299;
    }
    i__1 = *k;
    for (l = 1; l <= i__1; ++l) {
	i__2 = *n;
	for (i__ = 2; i__ <= i__2; ++i__) {
	    im1 = i__ - 1;
	    s21 = -b[i__ + l * b_dim1];
	    i__3 = im1;
	    for (j = 1; j <= i__3; ++j) {
		s21 = (doublereal) a[i__ + j * a_dim1] * (doublereal) b[j + l 
			* b_dim1] + s21;
/* L231: */
	    }
	    b[i__ + l * b_dim1] = -a[i__ + i__ * a_dim1] * s21;
/* L232: */
	}
	nm1 = *n - 1;
	i__2 = nm1;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    nmi = *n - i__;
	    s22 = -b[nmi + l * b_dim1];
	    i__3 = i__;
	    for (j = 1; j <= i__3; ++j) {
		nmjp1 = *n - j + 1;
		s22 = (doublereal) a[nmi + nmjp1 * a_dim1] * (doublereal) b[
			nmjp1 + l * b_dim1] + s22;
/* L241: */
	    }
	    b[nmi + l * b_dim1] = -s22;
/* L242: */
	}
/* L243: */
    }
L299:
    return 0;
} /* rfeqn_ */

/* Subroutine */ int dfeqn_(integer *n, doublereal *a, integer *idim, integer 
	*ir, integer *k, doublereal *b)
{
    /* Initialized data */

    static char hname[6] = " DFEQN";

    /* System generated locals */
    integer a_dim1, a_offset, b_dim1, b_offset, i__1, i__2, i__3;

    /* Local variables */
    static integer i__, j, l, m, ij;
    static doublereal s21, s22, te;
    static integer im1, nm1, nmi, nxch, nmjp1;
    extern /* Subroutine */ int tmprnt_(char *, integer *, integer *, integer 
	    *, ftnlen);

    /* Parameter adjustments */
    b_dim1 = *idim;
    b_offset = 1 + b_dim1;
    b -= b_offset;
    a_dim1 = *idim;
    a_offset = 1 + a_dim1;
    a -= a_offset;
    --ir;

    /* Function Body */
/* $OMP THREADPRIVATE(i,ij,im1,j,l,m,nm1,nmi,nmjp1,nxch, */
/* $OMP& x,y,te,s21,s22,hname) */
/* ----------------------------------------------------------------------- */
    if (*idim >= *n && *n > 0 && *k > 0) {
	goto L210;
    }
    tmprnt_(hname, n, idim, k, (ftnlen)6);
    return 0;
L210:
    nxch = ir[*n];
    if (nxch == 0) {
	goto L220;
    }
    i__1 = nxch;
    for (m = 1; m <= i__1; ++m) {
	ij = ir[m];
	i__ = ij / 4096;
	j = ij % 4096;
	i__2 = *k;
	for (l = 1; l <= i__2; ++l) {
	    te = b[i__ + l * b_dim1];
	    b[i__ + l * b_dim1] = b[j + l * b_dim1];
	    b[j + l * b_dim1] = te;
/* L211: */
	}
/* L212: */
    }
L220:
    i__1 = *k;
    for (l = 1; l <= i__1; ++l) {
	b[l * b_dim1 + 1] = a[a_dim1 + 1] * b[l * b_dim1 + 1];
/* L221: */
    }
    if (*n == 1) {
	goto L299;
    }
    i__1 = *k;
    for (l = 1; l <= i__1; ++l) {
	i__2 = *n;
	for (i__ = 2; i__ <= i__2; ++i__) {
	    im1 = i__ - 1;
	    s21 = -b[i__ + l * b_dim1];
	    i__3 = im1;
	    for (j = 1; j <= i__3; ++j) {
		s21 = a[i__ + j * a_dim1] * b[j + l * b_dim1] + s21;
/* L231: */
	    }
	    b[i__ + l * b_dim1] = -a[i__ + i__ * a_dim1] * s21;
/* L232: */
	}
	nm1 = *n - 1;
	i__2 = nm1;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    nmi = *n - i__;
	    s22 = -b[nmi + l * b_dim1];
	    i__3 = i__;
	    for (j = 1; j <= i__3; ++j) {
		nmjp1 = *n - j + 1;
		s22 = a[nmi + nmjp1 * a_dim1] * b[nmjp1 + l * b_dim1] + s22;
/* L241: */
	    }
	    b[nmi + l * b_dim1] = -s22;
/* L242: */
	}
/* L243: */
    }
L299:
    return 0;
} /* dfeqn_ */

/* Subroutine */ int rfinv_(integer *n, real *a, integer *idim, integer *ir)
{
    /* Initialized data */

    static doublereal zero = 0.;
    static char hname[6] = " RFINV";

    /* System generated locals */
    integer a_dim1, a_offset, i__1, i__2, i__3;

    /* Local variables */
    static integer i__, j, k, m, ij;
    static doublereal s31, s32, s33, s34;
    static real ti;
    static integer im2, nm1, nmi, nxch;
    extern /* Subroutine */ int tmprnt_(char *, integer *, integer *, integer 
	    *, ftnlen);

    /* Parameter adjustments */
    a_dim1 = *idim;
    a_offset = 1 + a_dim1;
    a -= a_offset;
    --ir;

    /* Function Body */
/* $OMP THREADPRIVATE(i,ij,im2,j,k,m,nm1,nmi,nxch, */
/* $OMP& ti,x,y,s31,s32,s33,s34,zero,hname) */
/* ----------------------------------------------------------------------- */
    if (*idim >= *n && *n > 0) {
	goto L310;
    }
    tmprnt_(hname, n, idim, &c__0, (ftnlen)6);
    return 0;
L310:
    if (*n == 1) {
	return 0;
    }
    a[a_dim1 + 2] = -a[(a_dim1 << 1) + 2] * ((doublereal) a[a_dim1 + 1] * (
	    doublereal) a[a_dim1 + 2] + zero);
    a[(a_dim1 << 1) + 1] = -a[(a_dim1 << 1) + 1];
    if (*n == 2) {
	goto L330;
    }
    i__1 = *n;
    for (i__ = 3; i__ <= i__1; ++i__) {
	im2 = i__ - 2;
	i__2 = im2;
	for (j = 1; j <= i__2; ++j) {
	    s31 = zero;
	    s32 = a[j + i__ * a_dim1];
	    i__3 = im2;
	    for (k = j; k <= i__3; ++k) {
		s31 = (doublereal) a[k + j * a_dim1] * (doublereal) a[i__ + k 
			* a_dim1] + s31;
		s32 = (doublereal) a[j + (k + 1) * a_dim1] * (doublereal) a[k 
			+ 1 + i__ * a_dim1] + s32;
/* L311: */
	    }
	    a[i__ + j * a_dim1] = -a[i__ + i__ * a_dim1] * ((doublereal) a[
		    i__ - 1 + j * a_dim1] * (doublereal) a[i__ + (i__ - 1) * 
		    a_dim1] + s31);
	    a[j + i__ * a_dim1] = -s32;
/* L312: */
	}
	a[i__ + (i__ - 1) * a_dim1] = -a[i__ + i__ * a_dim1] * ((doublereal) 
		a[i__ - 1 + (i__ - 1) * a_dim1] * (doublereal) a[i__ + (i__ - 
		1) * a_dim1] + zero);
	a[i__ - 1 + i__ * a_dim1] = -a[i__ - 1 + i__ * a_dim1];
/* L314: */
    }
L330:
    nm1 = *n - 1;
    i__1 = nm1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	nmi = *n - i__;
	i__2 = i__;
	for (j = 1; j <= i__2; ++j) {
	    s33 = a[i__ + j * a_dim1];
	    i__3 = nmi;
	    for (k = 1; k <= i__3; ++k) {
		s33 = (doublereal) a[i__ + k + j * a_dim1] * (doublereal) a[
			i__ + (i__ + k) * a_dim1] + s33;
/* L331: */
	    }
	    a[i__ + j * a_dim1] = s33;
/* L332: */
	}
	i__2 = nmi;
	for (j = 1; j <= i__2; ++j) {
	    s34 = zero;
	    i__3 = nmi;
	    for (k = j; k <= i__3; ++k) {
		s34 = (doublereal) a[i__ + k + (i__ + j) * a_dim1] * (
			doublereal) a[i__ + (i__ + k) * a_dim1] + s34;
/* L333: */
	    }
	    a[i__ + (i__ + j) * a_dim1] = s34;
/* L334: */
	}
/* L335: */
    }
    nxch = ir[*n];
    if (nxch == 0) {
	return 0;
    }
    i__1 = nxch;
    for (m = 1; m <= i__1; ++m) {
	k = nxch - m + 1;
	ij = ir[k];
	i__ = ij / 4096;
	j = ij % 4096;
	i__2 = *n;
	for (k = 1; k <= i__2; ++k) {
	    ti = a[k + i__ * a_dim1];
	    a[k + i__ * a_dim1] = a[k + j * a_dim1];
	    a[k + j * a_dim1] = ti;
/* L341: */
	}
/* L342: */
    }
    return 0;
} /* rfinv_ */

/* Subroutine */ int dfinv_(integer *n, doublereal *a, integer *idim, integer 
	*ir)
{
    /* Initialized data */

    static char hname[6] = " DFINV";
    static doublereal zero = 0.;

    /* System generated locals */
    integer a_dim1, a_offset, i__1, i__2, i__3;

    /* Local variables */
    static integer i__, j, k, m, ij;
    static doublereal s31, s32, s33, s34, ti;
    static integer im2, nm1, nmi, nxch;
    extern /* Subroutine */ int tmprnt_(char *, integer *, integer *, integer 
	    *, ftnlen);

    /* Parameter adjustments */
    a_dim1 = *idim;
    a_offset = 1 + a_dim1;
    a -= a_offset;
    --ir;

    /* Function Body */
/* $OMP THREADPRIVATE(i,ij,im2,j,k,m,nm1,nmi,nxch, */
/* $OMP& s31,s32,s33,s34,ti,x,y,zero,hname) */
/* ----------------------------------------------------------------------- */
    if (*idim >= *n && *n > 0) {
	goto L310;
    }
    tmprnt_(hname, n, idim, &c__0, (ftnlen)6);
    return 0;
L310:
    if (*n == 1) {
	return 0;
    }
    a[a_dim1 + 2] = -a[(a_dim1 << 1) + 2] * (a[a_dim1 + 1] * a[a_dim1 + 2] + 
	    zero);
    a[(a_dim1 << 1) + 1] = -a[(a_dim1 << 1) + 1];
    if (*n == 2) {
	goto L330;
    }
    i__1 = *n;
    for (i__ = 3; i__ <= i__1; ++i__) {
	im2 = i__ - 2;
	i__2 = im2;
	for (j = 1; j <= i__2; ++j) {
	    s31 = zero;
	    s32 = a[j + i__ * a_dim1];
	    i__3 = im2;
	    for (k = j; k <= i__3; ++k) {
		s31 = a[k + j * a_dim1] * a[i__ + k * a_dim1] + s31;
		s32 = a[j + (k + 1) * a_dim1] * a[k + 1 + i__ * a_dim1] + s32;
/* L311: */
	    }
	    a[i__ + j * a_dim1] = -a[i__ + i__ * a_dim1] * (a[i__ - 1 + j * 
		    a_dim1] * a[i__ + (i__ - 1) * a_dim1] + s31);
	    a[j + i__ * a_dim1] = -s32;
/* L312: */
	}
	a[i__ + (i__ - 1) * a_dim1] = -a[i__ + i__ * a_dim1] * (a[i__ - 1 + (
		i__ - 1) * a_dim1] * a[i__ + (i__ - 1) * a_dim1] + zero);
	a[i__ - 1 + i__ * a_dim1] = -a[i__ - 1 + i__ * a_dim1];
/* L314: */
    }
L330:
    nm1 = *n - 1;
    i__1 = nm1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	nmi = *n - i__;
	i__2 = i__;
	for (j = 1; j <= i__2; ++j) {
	    s33 = a[i__ + j * a_dim1];
	    i__3 = nmi;
	    for (k = 1; k <= i__3; ++k) {
		s33 = a[i__ + k + j * a_dim1] * a[i__ + (i__ + k) * a_dim1] + 
			s33;
/* L331: */
	    }
	    a[i__ + j * a_dim1] = s33;
/* L332: */
	}
	i__2 = nmi;
	for (j = 1; j <= i__2; ++j) {
	    s34 = zero;
	    i__3 = nmi;
	    for (k = j; k <= i__3; ++k) {
		s34 = a[i__ + k + (i__ + j) * a_dim1] * a[i__ + (i__ + k) * 
			a_dim1] + s34;
/* L333: */
	    }
	    a[i__ + (i__ + j) * a_dim1] = s34;
/* L334: */
	}
/* L335: */
    }
    nxch = ir[*n];
    if (nxch == 0) {
	return 0;
    }
    i__1 = nxch;
    for (m = 1; m <= i__1; ++m) {
	k = nxch - m + 1;
	ij = ir[k];
	i__ = ij / 4096;
	j = ij % 4096;
	i__2 = *n;
	for (k = 1; k <= i__2; ++k) {
	    ti = a[k + i__ * a_dim1];
	    a[k + i__ * a_dim1] = a[k + j * a_dim1];
	    a[k + j * a_dim1] = ti;
/* L341: */
	}
/* L342: */
    }
    return 0;
} /* dfinv_ */

/* Subroutine */ int tmprnt_(char *name__, integer *n, integer *idim, integer 
	*k, ftnlen name_len)
{
    /* Format strings */
    static char fmt_1002[] = "(7x,\002 parameter error in subroutine \002,"
	    "a6,\002 ... (n.lt.1 or idim.lt.n or k.lt.1).\002,5x,\002n =\002,"
	    "i4,5x,\002idim =\002,i4,5x,\002k =\002,i4,\002.\002)";
    static char fmt_1001[] = "(7x,\002 parameter error in subroutine \002,"
	    "a6,\002 ... (n.lt.1 or idim.lt.n).\002,5x,\002n =\002,i4,5x,\002"
	    "idim =\002,i4,\002.\002)";

    /* System generated locals */
    cilist ci__1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer ifmt;
    extern /* Subroutine */ int abend_(void);
    static logical mflag, rflag;
    static integer lgfile;
    extern /* Subroutine */ int kermtr_(char *, integer *, logical *, logical 
	    *, ftnlen);

    /* Assigned format variables */
    static char *ifmt_fmt;

/* $OMP THREADPRIVATE(ifmt,lgfile,mflag,rflag) */
/* ----------------------------------------------------------------------- */
    if (*(unsigned char *)&name__[1] == 'S') {
	kermtr_("F012.1", &lgfile, &mflag, &rflag, (ftnlen)6);
    } else {
	kermtr_("F011.1", &lgfile, &mflag, &rflag, (ftnlen)6);
    }
    if (s_cmp(name__ + 2, "FEQN", (ftnlen)4, (ftnlen)4) == 0) {
	ifmt = 0;
	ifmt_fmt = fmt_1002;
    }
    if (s_cmp(name__ + 2, "FEQN", (ftnlen)4, (ftnlen)4) != 0) {
	ifmt = 1;
	ifmt_fmt = fmt_1001;
    }
    if (mflag) {
	if (lgfile == 0) {
	    if (s_cmp(name__ + 2, "FEQN", (ftnlen)4, (ftnlen)4) == 0) {
		ci__1.cierr = 0;
		ci__1.ciunit = 6;
		ci__1.cifmt = ifmt_fmt;
		s_wsfe(&ci__1);
		do_fio(&c__1, name__, (ftnlen)6);
		do_fio(&c__1, (char *)&(*n), (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&(*idim), (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&(*k), (ftnlen)sizeof(integer));
		e_wsfe();
	    } else {
		ci__1.cierr = 0;
		ci__1.ciunit = 6;
		ci__1.cifmt = ifmt_fmt;
		s_wsfe(&ci__1);
		do_fio(&c__1, name__, (ftnlen)6);
		do_fio(&c__1, (char *)&(*n), (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&(*idim), (ftnlen)sizeof(integer));
		e_wsfe();
	    }
	} else {
	    if (s_cmp(name__ + 2, "FEQN", (ftnlen)4, (ftnlen)4) == 0) {
		ci__1.cierr = 0;
		ci__1.ciunit = lgfile;
		ci__1.cifmt = ifmt_fmt;
		s_wsfe(&ci__1);
		do_fio(&c__1, name__, (ftnlen)6);
		do_fio(&c__1, (char *)&(*n), (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&(*idim), (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&(*k), (ftnlen)sizeof(integer));
		e_wsfe();
	    } else {
		ci__1.cierr = 0;
		ci__1.ciunit = lgfile;
		ci__1.cifmt = ifmt_fmt;
		s_wsfe(&ci__1);
		do_fio(&c__1, name__, (ftnlen)6);
		do_fio(&c__1, (char *)&(*n), (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&(*idim), (ftnlen)sizeof(integer));
		e_wsfe();
	    }
	}
    }
    if (! rflag) {
	abend_();
    }
    return 0;
L1001:
L1002:
    ;
} /* tmprnt_ */

/* Subroutine */ int lfit_(real *x, real *y, integer *l, integer *key, real *
	a, real *b, real *e)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer j;
    static real xmed, ymed, sumx, sumy, count, sumxx, sumxy, sumyy, scartx, 
	    scarty;

/* ----------------------------------------------------------------------- */

/*     TO FIT A STRAIGHT LINE    Y=A*X+B    TO L POINTS WITH ERROR E */
/*     SEE MENZEL , FORMULAS OF PHYSICS P.116 */
/*     POINTS WITH Y=0 ARE IGNOERD IF KEY=0 */
/*     L IS NO. OF POINTS */

/* ----------------------------------------------------------------------- */
/* $OMP THREADPRIVATE(j, */
/* $OMP& count,scartx,scarty,sumx,sumxx,sumxy,sumy,sumyy,xmed,ymed) */
/* ----------------------------------------------------------------------- */

/*     CALCULATE SUMS */

/* ----------------------------------------------------------------------- */
    /* Parameter adjustments */
    --y;
    --x;

    /* Function Body */
    if (*l - 2 >= 0) {
	goto L1;
    } else {
	goto L25;
    }
L1:
    count = 0.f;
    sumx = 0.f;
    sumy = 0.f;
    sumxy = 0.f;
    sumxx = 0.f;
    sumyy = 0.f;
    i__1 = *l;
    for (j = 1; j <= i__1; ++j) {
	if (y[j] == 0.f && *key == 0) {
	    goto L10;
	}
	sumx += x[j];
	sumy += y[j];
	count += 1.f;
L10:
	;
    }
    if (count <= 1.f) {
	goto L25;
    }
    ymed = sumy / count;
    xmed = sumx / count;
    i__1 = *l;
    for (j = 1; j <= i__1; ++j) {
	if (y[j] == 0.f && *key == 0) {
	    goto L20;
	}
	scartx = x[j] - xmed;
	scarty = y[j] - ymed;
	sumxy += scartx * scarty;
	sumxx += scartx * scartx;
	sumyy += scarty * scarty;
L20:
	;
    }

/*     FIT PARAMETERS */
    if (sumxx == 0.f) {
	goto L25;
    }
    *a = sumxy / sumxx;
    *b = ymed - *a * xmed;
    if (count < 3.f) {
	goto L101;
    }
    *e = (sumyy - sumxy * *a) / (count - 2.f);
    goto L100;

/*     ISUFFICIENT POINTS */
L25:
    *a = 0.f;
    *b = 0.f;
L101:
    *e = 0.f;
L100:
    return 0;
} /* lfit_ */

/* Subroutine */ int lfitw_(real *x, real *y, real *w, integer *l, integer *
	key, real *a, real *b, real *e)
{
    /* System generated locals */
    integer i__1;
    real r__1, r__2, r__3;

    /* Local variables */
    static integer j;
    static real w2, ww, w2x, w2y, w2x2, w2y2, wwf, w2xy;
    static integer icnt;
    static real wwfi;

/* ----------------------------------------------------------------------- */

/*     TO PERFORM A WEIGHTED STRAIGHT LINE FIT */

/*     FOR FORMULAE USED SEE MENZEL, FORMULAS OF PHYSICS P.116 */

/*     FIT IS OF Y=AX+B , WITH S**2 ESTIMATOR E. WEIGHTS ARE IN W. */
/*     IF KEY=0, POINTS WITH Y=0 ARE IGNORED */
/*     L IS NO. OF POINTS */

/* ----------------------------------------------------------------------- */
/* $OMP THREADPRIVATE(icnt,j, */
/* $OMP& w2,w2x,w2x2,w2xy,w2y,w2y2,ww,wwf,wwfi) */
/* ----------------------------------------------------------------------- */

/*     CALCULATE SUMS */

/* ----------------------------------------------------------------------- */
    /* Parameter adjustments */
    --w;
    --y;
    --x;

    /* Function Body */
    if (*l <= 1) {
	goto L1;
    }
    w2 = 0.f;
    w2x = 0.f;
    w2y = 0.f;
    w2xy = 0.f;
    w2x2 = 0.f;
    w2y2 = 0.f;
    icnt = 0;
    i__1 = *l;
    for (j = 1; j <= i__1; ++j) {
	if (y[j] == 0.f && *key == 0) {
	    goto L2;
	}
	ww = w[j] * w[j];
	w2 = ww + w2;
	wwf = ww * x[j];
	w2x = wwf + w2x;
	w2x2 = wwf * x[j] + w2x2;
	w2xy = wwf * y[j] + w2xy;
	wwfi = ww * y[j];
	w2y = wwfi + w2y;
	w2y2 = wwfi * y[j] + w2y2;
	++icnt;
L2:
	;
    }

/*     FIT PARAMETERS */
/* Computing 2nd power */
    r__1 = w2x;
    *a = (w2xy - w2x * w2y / w2) / (w2x2 - r__1 * r__1 / w2);
    *b = (w2y - *a * w2x) / w2;
    if (icnt <= 2) {
	goto L3;
    }
/* Computing 2nd power */
    r__1 = w2y;
/* Computing 2nd power */
    r__2 = w2xy - w2x * w2y / w2;
/* Computing 2nd power */
    r__3 = w2x;
    *e = (w2y2 - r__1 * r__1 / w2 - r__2 * r__2 / (w2x2 - r__3 * r__3 / w2)) /
	     (icnt - 2);
    goto L4;

/*     ISUFFICIENT POINTS */
L1:
    *a = 0.f;
    *b = 0.f;
L3:
    *e = 0.f;
L4:
    return 0;
} /* lfitw_ */

/* Subroutine */ int abend_(void)
{
    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);

    /* Fortran I/O blocks */
    static cilist io___838 = { 0, 6, 0, 0, 0 };


    s_wsle(&io___838);
    do_lio(&c__9, &c__1, "abend called ==> problem", (ftnlen)24);
    e_wsle();
    return 0;
} /* abend_ */


/* $Id: cfft.F,v 1.1.1.1 1996/02/15 17:48:48 mclareni Exp $ */

/* $Log: cfft.F,v $ */
/* Revision 1.1.1.1  1996/02/15 17:48:48  mclareni */
/* Kernlib */


/* #include "pilot.h" */
/* Subroutine */ int cfft_(complex *a, integer *msign)
{
    /* System generated locals */
    integer i__1, i__2, i__3, i__4, i__5, i__6;
    complex q__1;

    /* Builtin functions */
    integer pow_ii(integer *, integer *), i_sign(integer *, integer *);
    double sqrt(doublereal), r_imag(complex *);

    /* Local variables */
    static real c__;
    static integer i__, j, k, l, m, n;
    static real s;
    static complex t, u, w;
    static integer le, ip, le1, nm1, nv2;

/* $OMP THREADPRIVATE(m,n,msign,nv2,nm1,i,j,k,le,le1,l,ip,c,s,U,W,T) */
    /* Parameter adjustments */
    --a;

    /* Function Body */
    if (*msign == 0) {
	return 0;
    }
    m = abs(*msign);
    n = pow_ii(&c__2, &m);
    nv2 = n / 2;
    nm1 = n - 1;
    j = 1;
    i__1 = nm1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (i__ >= j) {
	    goto L5;
	}
	i__2 = j;
	t.r = a[i__2].r, t.i = a[i__2].i;
	i__2 = j;
	i__3 = i__;
	a[i__2].r = a[i__3].r, a[i__2].i = a[i__3].i;
	i__2 = i__;
	a[i__2].r = t.r, a[i__2].i = t.i;
L5:
	k = nv2;
L6:
	if (k >= j) {
	    goto L7;
	}
	j -= k;
	k /= 2;
	goto L6;
L7:
	j += k;
    }
    i__1 = n;
    for (i__ = 1; i__ <= i__1; i__ += 2) {
	i__2 = i__ + 1;
	t.r = a[i__2].r, t.i = a[i__2].i;
	i__2 = i__ + 1;
	i__3 = i__;
	q__1.r = a[i__3].r - t.r, q__1.i = a[i__3].i - t.i;
	a[i__2].r = q__1.r, a[i__2].i = q__1.i;
/* L8: */
	i__2 = i__;
	i__3 = i__;
	q__1.r = a[i__3].r + t.r, q__1.i = a[i__3].i + t.i;
	a[i__2].r = q__1.r, a[i__2].i = q__1.i;
    }
    if (m == 1) {
	return 0;
    }
    c__ = 0.f;
    s = (real) i_sign(&c__1, msign);
    le = 2;
    i__2 = m;
    for (l = 2; l <= i__2; ++l) {
	q__1.r = c__, q__1.i = s;
	w.r = q__1.r, w.i = q__1.i;
	u.r = w.r, u.i = w.i;
	c__ = sqrt(c__ * .5f + .5f);
	s = r_imag(&w) / (c__ + c__);
	le1 = le;
	le = le1 + le1;
	i__3 = n;
	i__1 = le;
	for (i__ = 1; i__1 < 0 ? i__ >= i__3 : i__ <= i__3; i__ += i__1) {
	    ip = i__ + le1;
	    i__4 = ip;
	    t.r = a[i__4].r, t.i = a[i__4].i;
	    i__4 = ip;
	    i__5 = i__;
	    q__1.r = a[i__5].r - t.r, q__1.i = a[i__5].i - t.i;
	    a[i__4].r = q__1.r, a[i__4].i = q__1.i;
/* L9: */
	    i__4 = i__;
	    i__5 = i__;
	    q__1.r = a[i__5].r + t.r, q__1.i = a[i__5].i + t.i;
	    a[i__4].r = q__1.r, a[i__4].i = q__1.i;
	}
	i__4 = le1;
	for (j = 2; j <= i__4; ++j) {
	    i__5 = n;
	    i__1 = le;
	    for (i__ = j; i__1 < 0 ? i__ >= i__5 : i__ <= i__5; i__ += i__1) {
		ip = i__ + le1;
		i__3 = ip;
		q__1.r = a[i__3].r * u.r - a[i__3].i * u.i, q__1.i = a[i__3]
			.r * u.i + a[i__3].i * u.r;
		t.r = q__1.r, t.i = q__1.i;
		i__3 = ip;
		i__6 = i__;
		q__1.r = a[i__6].r - t.r, q__1.i = a[i__6].i - t.i;
		a[i__3].r = q__1.r, a[i__3].i = q__1.i;
/* L10: */
		i__3 = i__;
		i__6 = i__;
		q__1.r = a[i__6].r + t.r, q__1.i = a[i__6].i + t.i;
		a[i__3].r = q__1.r, a[i__3].i = q__1.i;
	    }
/* L20: */
	    q__1.r = u.r * w.r - u.i * w.i, q__1.i = u.r * w.i + u.i * w.r;
	    u.r = q__1.r, u.i = q__1.i;
	}
    }
    return 0;
} /* cfft_ */

