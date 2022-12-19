#include "utilities/filedownloader.h"

//====================================================================
//=== FileDownloader
//====================================================================
FileDownloader::FileDownloader(QObject* parent)
  : QObject(parent)
{
  setup();
}

FileDownloader::FileDownloader(const QUrl& url, QObject* parent)
  : m_url(url)
{
  setup();
}

FileDownloader::FileDownloader(const QString& url, QObject* parent)
  : m_url(QUrl(url))
{
  setup();
}

FileDownloader::~FileDownloader() {}

void
FileDownloader::setup()
{
  m_controller = new QNetworkAccessManager(this);
  connect(m_controller,
          &QNetworkAccessManager::finished,
          this,
          &FileDownloader::fileDownloaded);
}

void
FileDownloader::fileDownloaded(QNetworkReply* reply)
{
  qDebug() << "Reply received";
  if (reply->error()) {
    qDebug() << "ERROR!";
    qDebug() << reply->errorString();
  } else {
    emit dataDownloaded(reply->readAll());
    reply->deleteLater();
    emit finished();
  }
}

void
FileDownloader::setDownloadUrl(const QString& urlStr)
{
  m_url = QUrl(urlStr);
}

void
FileDownloader::setDownloadUrl(QUrl url)
{
  m_url = url;
}

void
FileDownloader::download()
{
  if (!m_url.isEmpty()) {
    QNetworkRequest request(m_url);
    m_controller->get(request);
  } else {
    emit error(tr("Error: Url has not been set!"));
  }
}

////====================================================================
////=== DownloadWorker
////====================================================================
//DownloadWorker::DownloadWorker(const QUrl& url)
//  : m_url(url)
//{
//}

//DownloadWorker::DownloadWorker(const QString& url)
//  : m_url(QUrl(url))
//{
//}

//DownloadWorker::~DownloadWorker() {}

//void
//DownloadWorker::process()
//{
//  auto downloader = new FileDownloader(this);
//  downloader->setDownloadUrl(m_url);
//  connect(downloader, &FileDownloader::error, this, &DownloadWorker::error);
//  connect(downloader,
//          &FileDownloader::dataDownloaded,
//          this,
//          &DownloadWorker::dataDownloaded);
//  connect(
//    downloader, &FileDownloader::finished, this, &DownloadWorker::finished);
//  downloader->download();
//}
