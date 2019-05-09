

ICaptureGraphBuilder2 *pCapGraBuilder2;
HRESULT hr = CoCreateInstance(CLSID_CaptureGraphBuilder2, NULL, CLSCTX_INPROC_SERVER, IID_ICaptureGraphBuilder2, (void**)&pCapGraBuilder2);
assert(hr >= 0);
IGraphBuilder *pGraBuilder;
hr = CoCreateInstance(CLSID_FilterGraph, 0, CLSCTX_INPROC_SERVER, IID_IGraphBuilder, (void**)&pGraBuilder);
assert(hr >= 0);
hr = pCapGraBuilder2->SetFiltergraph(pGraBuilder);
assert(hr >= 0);
IMediaControl *pMediaControl;
hr = pGraBuilder->QueryInterface(IID_IMediaControl, (void**)&pMediaControl);
assert(hr >= 0);
IMediaEvent *pMediaEvent;
hr = pGraBuilder->QueryInterface(IID_IMediaEvent, (void**)&pMediaEvent);







