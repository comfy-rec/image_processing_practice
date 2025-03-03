﻿
// ImageProcessing1View.cpp: CImageProcessing1View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "ImageProcessing1.h"
#endif

#include "ImageProcessing1Doc.h"
#include "ImageProcessing1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CImageProcessing1View

IMPLEMENT_DYNCREATE(CImageProcessing1View, CView)

BEGIN_MESSAGE_MAP(CImageProcessing1View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CImageProcessing1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_DOWN_SAMPLING, &CImageProcessing1View::OnDownSampling)
	ON_COMMAND(ID_Up_Sampling, &CImageProcessing1View::OnUpSampling)
	ON_COMMAND(ID_QUANTIZATION, &CImageProcessing1View::OnQuantization)
	ON_COMMAND(ID_SUM_CONSTANT, &CImageProcessing1View::OnSumConstant)
	ON_COMMAND(ID_SUB_CONSTANT, &CImageProcessing1View::OnSubConstant)
	ON_COMMAND(ID_MUL_CONSTANT, &CImageProcessing1View::OnMulConstant)
	ON_COMMAND(ID_DIV_CONSTANT, &CImageProcessing1View::OnDivConstant)
	ON_COMMAND(ID_AND_OPERATE, &CImageProcessing1View::OnAndOperate)
	ON_COMMAND(ID_OR_OPERATE, &CImageProcessing1View::OnOrOperate)
	ON_COMMAND(ID_XOR_OPERATE, &CImageProcessing1View::OnXorOperate)
	ON_COMMAND(ID_NEGA_TRANSFORM, &CImageProcessing1View::OnNegaTransform)
	ON_COMMAND(ID_GAMMA_CORRECTION, &CImageProcessing1View::OnGammaCorrection)
	ON_COMMAND(ID_BINARIZATION, &CImageProcessing1View::OnBinarization)
	ON_COMMAND(ID_STRESS_TRANSFORM, &CImageProcessing1View::OnStressTransform)
	ON_COMMAND(ID_HISTO_STRETCH, &CImageProcessing1View::OnHistoStretch)
	ON_COMMAND(ID_END_IN_SEARCH, &CImageProcessing1View::OnEndInSearch)
	ON_COMMAND(ID_HISTOGRAM, &CImageProcessing1View::OnHistogram)
	ON_COMMAND(ID_HISTO_EQUAL, &CImageProcessing1View::OnHistoEqual)
	ON_COMMAND(ID_HISTO_SPEC, &CImageProcessing1View::OnHistoSpec)
	ON_COMMAND(ID_EMBOSSING, &CImageProcessing1View::OnEmbossing)
	ON_COMMAND(ID_BLURR, &CImageProcessing1View::OnBlurr)
	ON_COMMAND(ID_GAUSSIAN_FILTER, &CImageProcessing1View::OnGaussianFilter)
	ON_COMMAND(ID_SHARPENING, &CImageProcessing1View::OnSharpening)
	ON_COMMAND(ID_HPF_SHARP, &CImageProcessing1View::OnHpfSharp)
	ON_COMMAND(ID_LPF_SHARP, &CImageProcessing1View::OnLpfSharp)
	ON_COMMAND(ID_DIFF_OPERATOR_HOR, &CImageProcessing1View::OnDiffOperatorHor)
	ON_COMMAND(ID_HOMOGEN_OPERATOR, &CImageProcessing1View::OnHomogenOperator)
	ON_COMMAND(ID_LAPLACIAN, &CImageProcessing1View::OnLaplacian)
	ON_COMMAND(ID_NEAREST, &CImageProcessing1View::OnNearest)
	ON_COMMAND(ID_BILINEAR, &CImageProcessing1View::OnBilinear)
	ON_COMMAND(ID_MEDIAN_SUB, &CImageProcessing1View::OnMedianSub)
	ON_COMMAND(ID_MEAN_SUB, &CImageProcessing1View::OnMeanSub)
	ON_COMMAND(ID_TRANSLATION, &CImageProcessing1View::OnTranslation)
	ON_COMMAND(ID_MIRROR_HOR, &CImageProcessing1View::OnMirrorHor)
	ON_COMMAND(ID_MIRROR_VER, &CImageProcessing1View::OnMirrorVer)
	ON_COMMAND(ID_ROTATION, &CImageProcessing1View::OnRotation)
	ON_COMMAND(ID_FRAME_SUM, &CImageProcessing1View::OnFrameSum)
	ON_COMMAND(ID_FRAME_SUB, &CImageProcessing1View::OnFrameSub)
	ON_COMMAND(ID_FRAME_MUL, &CImageProcessing1View::OnFrameMul)
	ON_COMMAND(ID_FRAME_DIV, &CImageProcessing1View::OnFrameDiv)
	ON_COMMAND(ID_FRAME_AND, &CImageProcessing1View::OnFrameAnd)
	ON_COMMAND(ID_FRAME_OR, &CImageProcessing1View::OnFrameOr)
	ON_COMMAND(ID_FRAME_COMB, &CImageProcessing1View::OnFrameComb)
	ON_COMMAND(ID_BINARY_EROSION, &CImageProcessing1View::OnBinaryErosion)
	ON_COMMAND(ID_BINARY_DILATION, &CImageProcessing1View::OnBinaryDilation)
	ON_COMMAND(ID_GRAY_EROSION, &CImageProcessing1View::OnGrayErosion)
	ON_COMMAND(ID_GRAY_DILATION, &CImageProcessing1View::OnGrayDilation)
	ON_COMMAND(ID_LOW_PASS_FILTER, &CImageProcessing1View::OnLowPassFilter)
	ON_COMMAND(ID_HIGH_PASS_FILTER, &CImageProcessing1View::OnHighPassFilter)
	ON_COMMAND(ID_MEAN_FILTER, &CImageProcessing1View::OnMeanFilter)
	ON_COMMAND(ID_MEDIAN_FILTER, &CImageProcessing1View::OnMedianFilter)
	ON_COMMAND(ID_MAX_FILTER, &CImageProcessing1View::OnMaxFilter)
	ON_COMMAND(ID_MIN_FILTER, &CImageProcessing1View::OnMinFilter)
	ON_COMMAND(ID_FFT_2D, &CImageProcessing1View::OnFft2d)
	ON_COMMAND(ID_IFFT_2D, &CImageProcessing1View::OnIfft2d)
	ON_COMMAND(ID_LPF_FREQUENCY, &CImageProcessing1View::OnLpfFrequency)
	ON_COMMAND(ID_HPF_FREQUENCY, &CImageProcessing1View::OnHpfFrequency)
END_MESSAGE_MAP()

// CImageProcessing1View 생성/소멸

CImageProcessing1View::CImageProcessing1View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CImageProcessing1View::~CImageProcessing1View()
{
}

BOOL CImageProcessing1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CImageProcessing1View 그리기

void CImageProcessing1View::OnDraw(CDC* pDC)
{
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	int i, j;
	unsigned char R, G, B;

	for (i = 0; i < pDoc->m_height; i++) {
		for (j = 0; j < pDoc->m_width; j++) {
			R = G = B = pDoc->m_InputImage[i * pDoc->m_width + j];
			pDC->SetPixel(j + 5, i + 5, RGB(R, G, B));
		}
	}

	// 축소된 영상 출력
	for (i = 0; i < pDoc->m_Re_height; i++) {
		for (j = 0; j < pDoc->m_Re_width; j++) {
			R = pDoc->m_OutputImage[i * pDoc->m_Re_width + j];
			G = B = R;
			pDC->SetPixel(j + pDoc->m_width + 10, i + 5, RGB(R, G, B));
		}
	}
}


// CImageProcessing1View 인쇄


void CImageProcessing1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CImageProcessing1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CImageProcessing1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CImageProcessing1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CImageProcessing1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CImageProcessing1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CImageProcessing1View 진단

#ifdef _DEBUG
void CImageProcessing1View::AssertValid() const
{
	CView::AssertValid();
}

void CImageProcessing1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CImageProcessing1Doc* CImageProcessing1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImageProcessing1Doc)));
	return (CImageProcessing1Doc*)m_pDocument;
}
#endif //_DEBUG


// CImageProcessing1View 메시지 처리기


void CImageProcessing1View::OnDownSampling()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	//AfxMessageBox(L"Down Sample!!");
	// TODO: Add your command handler code here
	CImageProcessing1Doc* pDoc = GetDocument(); // Doc 클래스 참조
	ASSERT_VALID(pDoc);

	pDoc->OnDownSampling(); // Doc 클래스에 OnDownSampling 함수 호출

	Invalidate(TRUE); // 화면 갱신
}


void CImageProcessing1View::OnUpSampling()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	// TODO: Add your command handler code here
	CImageProcessing1Doc* pDoc = GetDocument(); // Doc 클래스 참조
	ASSERT_VALID(pDoc);

	pDoc->OnUpSampling(); // Doc 클래스에 OnUpSampling 함수 호출

	Invalidate(TRUE); // 화면 갱신
}



void CImageProcessing1View::OnQuantization()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	// TODO: Add your command handler code here
	CImageProcessing1Doc* pDoc = GetDocument(); // Doc 클래스 참조
	ASSERT_VALID(pDoc);

	pDoc->OnQuantization(); // Doc 클래스에 OnQuantization 함수 호출

	Invalidate(TRUE); // 화면 갱신
}


void CImageProcessing1View::OnSumConstant()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	// TODO: Add your command handler code here
	CImageProcessing1Doc* pDoc = GetDocument();
	// 도큐먼트 클래스 참조
	ASSERT_VALID(pDoc); // 인스턴스 주소를 가져옴

	pDoc->OnSumConstant();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnSubConstant()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	// TODO: Add your command handler code here
	CImageProcessing1Doc* pDoc = GetDocument();// 도큐먼트 클래스 참조
	ASSERT_VALID(pDoc); // 인스턴스 주소를 가져옴

	pDoc->OnSubConstant();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnMulConstant()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	// TODO: Add your command handler code here
	CImageProcessing1Doc* pDoc = GetDocument(); // 도큐먼트 클래스 참조
	ASSERT_VALID(pDoc); // 인스턴스 주소를 가져옴

	pDoc->OnMulConstant();

	Invalidate(TRUE);

}


void CImageProcessing1View::OnDivConstant()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	// TODO: Add your command handler code here
	CImageProcessing1Doc* pDoc = GetDocument(); // 도큐먼트 클래스 참조
	ASSERT_VALID(pDoc); // 인스턴스 주소를 가져옴

	pDoc->OnDivConstant();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnAndOperate()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	// TODO: Add your command handler code here
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnAndOperate();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnOrOperate()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	// TODO: Add your command handler code here
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnOrOperate();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnXorOperate()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	// TODO: Add your command handler code here
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnXorOperate();
	Invalidate(TRUE);
}


void CImageProcessing1View::OnNegaTransform()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	// TODO: Add your command handler code here
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnNegaTransform();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnGammaCorrection()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	// TODO: Add your command handler code here
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnGammaCorrection();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnBinarization()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	// TODO: Add your command handler code here
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnBinarization();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnStressTransform()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	// TODO: Add your command handler code here
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnStressTransform();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnHistoStretch()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnHistoStretch();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnEndInSearch()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnEndInSearch();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnHistogram()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnHistogram();
	Invalidate(TRUE);
}


void CImageProcessing1View::OnHistoEqual()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnHistoEqual();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnHistoSpec()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnHistoSpec();

		Invalidate(TRUE);
}


void CImageProcessing1View::OnEmbossing()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnEmbossing();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnBlurr()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnBlurr();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnGaussianFilter()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnGaussianFilter();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnSharpening()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnSharpening();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnHpfSharp()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnHpfSharp();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnLpfSharp()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnLpfSharp();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnDiffOperatorHor()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnDiffOperatorHor();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnHomogenOperator()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnHomogenOperator();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnLaplacian()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnLaplacian();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnNearest()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnNearest();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnBilinear()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnBilinear();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnMedianSub()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMedianSub();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnMeanSub()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMeanSub();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnTranslation()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnTranslation();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnMirrorHor()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMirrorHor();

	Invalidate(TRUE);

}


void CImageProcessing1View::OnMirrorVer()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMirrorVer();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnRotation()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnRotation();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnFrameSum()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnFrameSum();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnFrameSub()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnFrameSub();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnFrameMul()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnFrameMul();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnFrameDiv()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnFrameDiv();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnFrameAnd()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnFrameAnd();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnFrameOr()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnFrameOr();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnFrameComb()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnFrameComb();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnBinaryErosion()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnBinaryErosion();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnBinaryDilation()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnBinaryDilation();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnGrayErosion()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnGrayErosion();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnGrayDilation()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnGrayDilation();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnLowPassFilter()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnLowPassFilter();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnHighPassFilter()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnHighPassFilter();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnMeanFilter()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMeanFilter();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnMedianFilter()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMedianFilter();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnMaxFilter()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMaxFilter();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnMinFilter()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMinFilter();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnFft2d()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnFft2d();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnIfft2d()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnIfft2d();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnLpfFrequency()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnLpfFrequency();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnHpfFrequency()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnHpfFrequency();

	Invalidate(TRUE);
}
