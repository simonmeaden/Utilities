#ifndef FILEDOWNLOADER_H
#define FILEDOWNLOADER_H

#include <QByteArray>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QObject>

#include "utilities_global.h"

//class FileDownloader;
//class SM_WIDGETS_SHARED_EXPORT DownloadWorker : public QObject
//{
//  Q_OBJECT
//public:
//  explicit DownloadWorker(const QUrl& url);
//  explicit DownloadWorker(const QString& url);
//  ~DownloadWorker();

//  void process();

//signals:
//  //! emitted when the download is complete.
//  void finished();
//  //! Emitted if a download error occurs.
//  void error(QString err);
//  //! emited when the download is complete, transmitting the returned data.
//  void dataDownloaded(const QByteArray& data);

//private:
//  QUrl m_url;
//};

/*!
  \ingroup utilities
  \file filedownloader.h
  \class FileDownloader filedownloader.h "utilities/filedownloader.h"
  \brief An http file downloader.

  A simple class that allows a file to be downloaded over the internet.

  This was based closely on the 'Download Data from URL' tutorial.
*/
class UTILITIES_SHARED_EXPORT FileDownloader : public QObject
{
  Q_OBJECT
public:
  //! Constructor for FileDownloader
  explicit FileDownloader(QObject* parent = nullptr);
  explicit FileDownloader(const QUrl& url,QObject* parent = nullptr);
  explicit FileDownloader(const QString& url,QObject* parent = nullptr);
  virtual ~FileDownloader();

  //! Sets the URL of the file to download as a QString.
  void setDownloadUrl(const QString& urlStr);
  //! Sets the URL of the file to download as a QUrl.
  void setDownloadUrl(QUrl url);
  //! Starts the download process.
  void download();

signals:
  //! emitted when the download is complete.
  void finished();
  //! emited when the download is complete, transmitting the returned data.
  void dataDownloaded(const QByteArray& data);
  //! Emitted if a download error occurs.
  void error(const QString& errorStr);

private:
  QNetworkAccessManager* m_controller;
  QByteArray m_downloadedData;
  QUrl m_url;

  void fileDownloaded(QNetworkReply* pReply);
  void setup();
};

#endif // FILEDOWNLOADER_H
